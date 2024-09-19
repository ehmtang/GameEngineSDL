#include "src/core/GameApp.h"
#include "src/managers/GameObjectManager.h"
#include "src/managers/TextureManager.h"

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

// macro code for logging?
// #ifdef _DEBUG
//std::cerr << "SDL failed to initialise: " << SDL_GetError() << std::endl; send to text file
//__debugbreak();
//#endif // _DEBUG
//#define LOGGER

GameObject* player;

GameApp::GameApp()
	: m_isRunning(true)
	, m_window(nullptr)
	, m_renderer(nullptr)
{}

GameApp::~GameApp()
{

}

// change this to desc. pattern
void GameApp::Initialise(GameAppMap& desc)
{
	// Check for fullscreen
	int flags = 0;
	if (desc.fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// Check SDL initialisation
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
#ifdef _DEBUG
		std::cerr << "SDL failed to initialise: " << SDL_GetError() << std::endl;
		__debugbreak();
#endif // _DEBUG
		return;
	}

	// Check window initialisation
	m_window = SDL_CreateWindow(desc.title, desc.xpos, desc.ypos, desc.width, desc.height, flags);
	if (m_window == nullptr)
	{
		std::cerr << "Window failed to initialise: " << SDL_GetError() << std::endl;
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
	player = GameObjectManager::Instance().CreateGameObject<GameObject>("assets/playerGreen_up1.png", m_renderer);


	// Initialisation complete, set game loop flag to true
	m_isRunning = true;
}

void GameApp::Update(float deltaTime)
{
	GameObjectManager::Instance().Update(deltaTime);
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