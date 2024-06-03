#pragma once

#include "SDL_image.h"
#include "src/core/GameApp.h"


class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	TextureManager(const TextureManager& ) = delete;
	TextureManager operator = (const TextureManager& ) = delete;
	
	static SDL_Texture* LoadTexture(const char* path, SDL_Renderer* renderer);

private:
};
