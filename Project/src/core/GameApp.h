#pragma once

#include <SDL_main.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_timer.h>

#include <assert.h>
#include <iostream>
#include <string>

class GameApp
{
public:
	GameApp();
	~GameApp();

	GameApp(const GameApp&) = delete;
	GameApp operator = (const GameApp&) = delete;

	struct GameAppMap
	{
		const char* title;
		int xpos{ 0 };
		int ypos{ 0 };
		int width{ 720 };
		int height{ 540 };
		bool fullscreen{ false };
	};

	void Initialise(GameAppMap& desc);
	void Update(float deltaTime);
	void Render();
	void Shutdown();
	bool Running() { return m_isRunning; }
	void HandleEvents();
	



private:
	void LoadAssets();// should be asset 

	bool m_isRunning;
	SDL_Window* m_window;		// The window we'll be rendering to
	SDL_Renderer* m_renderer;	// Window renderer



};
