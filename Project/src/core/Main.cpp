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

	// times go inside a static global or singleton?
	const Uint32 fps = 60;
	const Uint32 frameDelay = 1000 / fps;
	Uint32 frameStart = 0;
	Uint32 frameTime = 0;
	Uint32 lastFrameTime = 0;


	// Initialise game application
	GameApp app;
	GameApp::GameAppMap desc;
	{
		desc.title = "2D Game Engine";
		desc.xpos = 50;
		desc.ypos = 50;
		desc.width = SCREEN_WIDTH;
		desc.height = SCREEN_HEIGHT;
		desc.fullscreen = false;
	}
	app.Initialise(desc);

	while (app.Running())
	{

		// this should be inside a method
		frameStart = SDL_GetTicks();
		float deltaTime = static_cast<float>(frameStart - lastFrameTime); // in ms
		lastFrameTime = frameStart;

		// handles the game application as a whole ie break out of app.Running while loop
		app.HandleEvents();
		
		// updates the game itself
		app.Update(deltaTime);
		
		// rendering the game
		app.Render();

		// so is this should be inside a method
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