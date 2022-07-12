#pragma once

#include "RAM.h"
#include "CPU.h"
#include "Display.h"
#include "Keyboard.h"

class Chip8
{
public:
	Chip8();
	Chip8(const Chip8&) = delete;
	~Chip8() = default;

	/* Loads program from a file */
	void LoadProgram(std::string filepath);

	/* Resets the device */
	void Reset(bool reload_program);

	/* Returns CPU */
	CPU& GetCPU() const;

	/* Returns RAM */
	RAM& GetRAM() const;

	/* Returns Display */
	Display& GetDisplay() const;

	/* Returns Keyboard */
	Keyboard& GetKeyboard() const;

	/* Updates display if should (only call it from the main thread) */
	bool UpdateDisplay();

	/* Set is paused */
	inline void SetPaused(bool new_state) { m_cpu->SetPaused(new_state); }

	/* Returns true if paused */
	const bool& IsPaused() const { return m_cpu->IsPaused(); }

private:
	/* Devices */
	std::shared_ptr<Keyboard> m_keyboard;
	std::shared_ptr<Display> m_display;
	std::shared_ptr<CPU> m_cpu;
	std::shared_ptr<RAM> m_ram;

	/* State */
	std::string m_lastProgram;
};

