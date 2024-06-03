#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

class Texture {
public:
    Texture(SDL_Renderer* renderer);
    ~Texture();

    bool LoadFromFile(const std::string& path);
    void Free();

    void Render(int x, int y, SDL_Rect* clip = nullptr);

    int GetWidth() const;
    int GetHeight() const;

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    int width;
    int height;
};
