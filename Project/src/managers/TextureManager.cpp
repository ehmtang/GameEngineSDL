#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* path, SDL_Renderer* renderer)
{
	SDL_Surface* tmpSurface = IMG_Load(path);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	if (texture == nullptr)
	{
		std::cerr << "Texture failed to load: " << SDL_GetError() << std::endl;
		__debugbreak();
	}
	return texture;
}
