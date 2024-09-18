#pragma once

#include <SDL.h>
#include <SDL_image.h>

// change to singleton and rename as a manager


// this renders to the screen 
class Renderer 
{
public:
    Renderer(SDL_Window* window);
    void RenderTexture(SDL_Texture* texture, int x, int y, int w, int h);

private:
    SDL_Renderer* renderer;
};
