#include "stdafx.h"

#include <chrono>
#include <thread>
#include <Windows.h>

#include <devices/Chip8.h>

#include <iostream>
#include <mutex>

#define WINDOW_SCALE 8

GLFWwindow* g_window;

void Chip8Thread(Chip8& chip, std::mutex& chip_mutex, bool& is_running)
{
	double lastTimerTick = 0;
	double lastCPUTick = 0;
	
	double nextSecond = glfwGetTime() + 1.0;
	int times = 0;

	while (is_running)
	{
		auto tickStartTime = std::chrono::steady_clock::now();
		
		double currTime = glfwGetTime();
		double cpuTickDiff = currTime - lastCPUTick;
		double timerTickDiff = currTime - lastTimerTick;

		if (currTime >= nextSecond)
		{
			printf("Current CPU Rate: %d Hz (target clock is %d Hz)\n", times, CPU_HZ);
			nextSecond = glfwGetTime() + 1.0;
			times = 0;
		}

		// updating CPU 
		if (cpuTickDiff >= CPU_HZ_SECONDS)
		{
			lastCPUTick = currTime;
			times++;

			chip_mutex.lock();
			chip.GetCPU().TickCPU();
			chip_mutex.unlock();
		}

		// updating timers
		if (timerTickDiff >= CPU_TIMER_HZ_SECONDS)
		{
			lastTimerTick = currTime;

			chip_mutex.lock();
			chip.GetCPU().TickTimers();
			chip_mutex.unlock();
		}

	}
}

int main()
{
	bool is_running = true;

	if (!glfwInit()) return -1;

	g_window = glfwCreateWindow(DISPLAY_WIDTH * WINDOW_SCALE, DISPLAY_HEIGHT * WINDOW_SCALE, "Chip 8 Emulator", nullptr, nullptr);

	if (!g_window)
	{
		fprintf(stderr, "glfw: can't create window");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(g_window);
	glfwSwapInterval(1);
	GLenum glewStatus = glewInit();

	if (glewStatus == GLEW_OK)
	{
		fprintf(stdout, "using glew %s\n", glewGetString(GLEW_VERSION));

		Chip8 chip;
		chip.LoadProgram("roms/Brick (Brix hack, 1990).ch8");

		std::mutex chip_mutex;
		std::thread chip_thread(Chip8Thread, std::ref(chip), std::ref(chip_mutex), std::ref(is_running));

		while (!glfwWindowShouldClose(g_window))
		{
			chip_mutex.lock();

			// updating keyboard and the screen
			chip.GetKeyboard().Update(g_window);
			chip.UpdateDisplay();
			
			// rendering
			chip.GetDisplay().Render();

			// should we reset?
			if (glfwGetKey(g_window, GLFW_KEY_ENTER) == GLFW_PRESS) { chip.Reset(true); }

			chip_mutex.unlock();

			glfwSwapBuffers(g_window);
			glfwPollEvents();
		}

		// waiting for the Chip8 thread to finish
		is_running = false;
		chip_thread.join();
	}
	else
	{
		fprintf(stderr, "glew: error: %s\n", glewGetErrorString(glewStatus));
	}

	glfwTerminate();

	return 0;
}