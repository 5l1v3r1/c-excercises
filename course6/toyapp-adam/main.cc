#include <displaylib/surface_2d.h>
#include <displaylib/surface_3d.h>
#include <displaylib/window.h>
#include <scene.h>
#include <util/clock.h>
#include <util/keyboard.h>
#include <util/mouse.h>
#include <util/pixel.h>
#include <SDL2/SDL_main.h>
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <OBJ_FILE>" << std::endl;
		return 1;
	}

	Util::Pixel screenDimensions{1280, 720};

	Util::Keyboard keyboard;
	Util::Mouse mouse(screenDimensions[1]);
	Util::Clock clock;

	Display::Window win("Hello", 100, 100, screenDimensions[0], screenDimensions[1]);
	Display::Surface2D surface2D(screenDimensions);
	Display::Surface3D surface3D(surface2D);

	Scene scene(keyboard, mouse, surface3D);
	scene.LoadMesh(argv[1]);

	SDL_Event event;
	SDL_SetRelativeMouseMode(SDL_TRUE);

	while(true)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_KEYDOWN:
					keyboard.Press(SDL_GetScancodeFromKey(event.key.keysym.sym));
					break;
				case SDL_KEYUP:
					keyboard.Release(SDL_GetScancodeFromKey(event.key.keysym.sym));
					break;
				case SDL_MOUSEMOTION:
					mouse.AddDeltaPosition({event.motion.xrel, event.motion.yrel});
					break;
				case SDL_QUIT:
					goto quit;
			}
		}

		if(keyboard.IsPressed(SDL_SCANCODE_END))
			goto quit;

		scene.Update(clock.GetTotalElapsedSeconds());

		surface2D.Clear(Display::BLACK);
		scene.Draw();
		win.Display(surface2D);

		keyboard.ClearChanges();
		mouse.RecordPosition();
	}

	quit:
	return 0;
}
