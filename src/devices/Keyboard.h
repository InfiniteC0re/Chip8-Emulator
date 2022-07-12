#pragma once

enum class KeyboardKey : uint8_t
{
	KEY_1, KEY_2, KEY_3, KEY_C,
	KEY_4, KEY_5, KEY_6, KEY_D,
	KEY_7, KEY_8, KEY_9, KEY_E,
	KEY_A, KEY_0, KEY_B, KEY_F,
	KEYCOUNT
};

class Keyboard
{
public:
	Keyboard();
	~Keyboard() = default;
	Keyboard(const Keyboard&) = delete;

	/* Gets key state */
	inline const bool& GetKeyState(KeyboardKey key) const;

	/* Sets key state */
	inline void SetKeyState(KeyboardKey key, bool isPressed);

	/* Updates the state of keyboard */
	void Update(GLFWwindow* window);

private:
	uint8_t m_inputs[16];
};

inline const bool& Keyboard::GetKeyState(KeyboardKey key) const
{
	return m_inputs[(uint8_t)key];
}

inline void Keyboard::SetKeyState(KeyboardKey key, bool isPressed)
{
	m_inputs[(uint8_t)key] = isPressed;
}

