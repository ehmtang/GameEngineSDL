#include "Renderer.h"

Renderer::Renderer(SDL_Window* window) 
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // Check for renderer creation success
}

void Renderer::RenderTexture(SDL_Texture* texture, int x, int y, int w, int h) 
{
    SDL_Rect destRect = { x, y, w, h };
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}
