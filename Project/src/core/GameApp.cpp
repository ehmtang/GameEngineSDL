#include "src/core/GameApp.h"
#include "src/managers/GameObjectManager.h"
#include "src/managers/TextureManager.h"

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

GameObject* player;

GameApp::GameApp()
	: m_isRunning(true)
	, m_window(nullptr)
	, m_renderer(nullptr)
{}

GameApp::~GameApp()
{

}

void GameApp::Initialise(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	// Check for fullscreen
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// Check SDL initialisation
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << "SDL failed to initialise: " << SDL_GetError() << std::endl;
		__debugbreak();
		return;
	}

	// Check window initialisation
	m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
	if (m_window == nullptr)
	{
		std::cerr << "Window failed to intialise: " << SDL_GetError() << std::endl;
		__debugbreak();
		return;
	}

	// Check renderer initialisation
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (!m_renderer)
	{
		std::cerr << "Renderer failed to initialise: " << SDL_GetError() << std::endl;
		__debugbreak();
		return;
	}


	// Create player
	player = GameObjectManager::Instance().CreateGameObject<GameObject>("assets/particle/circle_01.png", m_renderer);


	// Initialisation complete, set gameloop flag to true
	m_isRunning = true;
}

void GameApp::Update(float dT)
{
	GameObjectManager::Instance().Update(dT);
}

void GameApp::Render()
{
	SDL_RenderClear(m_renderer);
	GameObjectManager::Instance().Render();
	SDL_RenderPresent(m_renderer);
}

//! @brief Shutdown game application, releasing windows, renderer and SDL.
void GameApp::Shutdown()
{
	// Clean up window, renderer and SDL
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}

void GameApp::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case(SDL_QUIT):
	{
		m_isRunning = false;
		break;
	}
	default:
	{
		break;
	}
	}
}