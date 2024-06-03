#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer)
	: renderer(renderer)
	, texture(nullptr)
	, width(0)
	, height(0)
{}

Texture::~Texture()
{
	Free();
}

bool Texture::LoadFromFile(const std::string& path) 
{
	Free();

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr) 
	{
		std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
		return false;
	}

	texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	if (texture == nullptr) 
	{
		std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
		SDL_FreeSurface(loadedSurface);
		return false;
	}

	width = loadedSurface->w;
	height = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);
	return true;
}

void Texture::Free() 
{
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
		width = 0;
		height = 0;
	}
}

void Texture::Render(int x, int y, SDL_Rect* clip /*= nullptr*/) 
{
	SDL_Rect renderQuad = { x, y, width, height };

	if (clip != nullptr) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy(renderer, texture, clip, &renderQuad);
}

int Texture::GetWidth() const 
{
	return width;
}

int Texture::GetHeight() const 
{
	return height;
}
