#pragma once

#include <cstdint>
#include <SDL2/SDL.h>

namespace Display {

class Keyboard
{
public:
	using KeyCode = SDL_Keycode;

	void Press(KeyCode keyCode);
	void Release(KeyCode keyCode);
	void ClearChanges();
	bool IsUp(KeyCode keyCode) const;
	bool IsDown(KeyCode keyCode) const;
	bool IsPressed(KeyCode keyCode) const;
	bool IsReleased(KeyCode keyCode) const;
private:
	struct KeyState
	{
		std::uint8_t up : 1;
		std::uint8_t down : 1;
		std::uint8_t pressed : 1;
		std::uint8_t released : 1;
	};

	static constexpr auto NUM_KEYCODES = SDL_NUM_SCANCODES;

	KeyState mKeys[NUM_KEYCODES];
};

}
