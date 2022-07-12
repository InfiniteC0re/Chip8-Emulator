#include "stdafx.h"
#include "Keyboard.h"

Keyboard::Keyboard()
{
	memset(m_inputs, 0, sizeof(m_inputs));
}

void Keyboard::Update(GLFWwindow* window)
{
	// first row
	SetKeyState(KeyboardKey::KEY_1, glfwGetKey(window, GLFW_KEY_1));
	SetKeyState(KeyboardKey::KEY_2, glfwGetKey(window, GLFW_KEY_2));
	SetKeyState(KeyboardKey::KEY_3, glfwGetKey(window, GLFW_KEY_3));
	SetKeyState(KeyboardKey::KEY_C, glfwGetKey(window, GLFW_KEY_4));

	// second row
	SetKeyState(KeyboardKey::KEY_4, glfwGetKey(window, GLFW_KEY_Q));
	SetKeyState(KeyboardKey::KEY_5, glfwGetKey(window, GLFW_KEY_W));
	SetKeyState(KeyboardKey::KEY_6, glfwGetKey(window, GLFW_KEY_E));
	SetKeyState(KeyboardKey::KEY_D, glfwGetKey(window, GLFW_KEY_R));

	// third row
	SetKeyState(KeyboardKey::KEY_7, glfwGetKey(window, GLFW_KEY_A));
	SetKeyState(KeyboardKey::KEY_8, glfwGetKey(window, GLFW_KEY_S));
	SetKeyState(KeyboardKey::KEY_9, glfwGetKey(window, GLFW_KEY_D));
	SetKeyState(KeyboardKey::KEY_E, glfwGetKey(window, GLFW_KEY_F));

	// fourth row
	SetKeyState(KeyboardKey::KEY_A, glfwGetKey(window, GLFW_KEY_Z));
	SetKeyState(KeyboardKey::KEY_0, glfwGetKey(window, GLFW_KEY_X));
	SetKeyState(KeyboardKey::KEY_B, glfwGetKey(window, GLFW_KEY_C));
	SetKeyState(KeyboardKey::KEY_F, glfwGetKey(window, GLFW_KEY_V));
}