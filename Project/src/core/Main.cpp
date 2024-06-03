///////////////////////////////////////////////////////////////////////////
//	2D Game Engine built with SDL2 library
//
///////////////////////////////////////////////////////////////////////////

#include "src/core/GameApp.h"

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 540;

int main(int argc, char* argv[])
{
	// reference formal parameters
	argc, argv;

	const Uint32 fps = 60;
	const Uint32 frameDelay = 1000 / fps;

	Uint32 frameStart = 0;
	Uint32 frameTime = 0;
	Uint32 lastFrameTime = 0;

	// Initialise game application
	GameApp app;
	app.Initialise("2D Game Engine", 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	while (app.Running())
	{
		frameStart = SDL_GetTicks();
		float deltaTime = static_cast<float>(frameStart - lastFrameTime); // in ms
		lastFrameTime = frameStart;

		app.HandleEvents();
		app.Update(deltaTime);
		app.Render();

		// Fixed framerate
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}

	app.Shutdown();

	return 0;
}