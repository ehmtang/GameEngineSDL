#pragma once
#include "src/core/GameApp.h"

enum class GameObjectType
{
    TYPE_NONE = 0,
    TYPE_PLAYER,
    TYPE_TOTAL,
};

class GameObject 
{
public:
    GameObject(const char* textureSheet, SDL_Renderer* renderer);
    ~GameObject();

    void Update(float deltaTime);
    void Render();
    bool IsDead() { return m_isDead; }

private:

    int x, y;
    bool m_isDead;
    GameObjectType m_type;
    SDL_Texture* m_objTexture;
    SDL_Rect m_srcRect, m_dstRect;
    SDL_Renderer* m_objRenderer;

};
