#pragma once

#include <SDL.h>

class Renderer {
public:
    Renderer(SDL_Window* window);
    void RenderTexture(SDL_Texture* texture, int x, int y, int w, int h);
private:
    SDL_Renderer* renderer;
};
