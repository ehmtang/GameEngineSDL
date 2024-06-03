#pragma once

#include <SDL.h>
#include <SDL_main.h>
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

	void Initialise(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void Update(float dT);
	void Render();
	void Shutdown();
	bool Running() { return m_isRunning; }
	void HandleEvents();

private:
	void LoadAssets();

	bool m_isRunning;
	SDL_Window* m_window;		// The window we'll be rendering to
	SDL_Renderer* m_renderer;	// Window renderer



};
