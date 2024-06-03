//#define GLM_FORCE_CXX17
#define GLM_FORCE_SILENT_WARNINGS
//#pragma warning(push)
//#pragma warning(disable:4201)   // suppress even more warnings about nameless structs
//#include<glm/glm.hpp>
//#pragma warning (pop)

#include "GameObject.h"
#include "src/managers/TextureManager.h"
#include "glm/glm.hpp"
#include "glm/gtx/dual_quaternion.hpp"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer)
{
	m_objRenderer = renderer;
	m_objTexture = TextureManager::LoadTexture(textureSheet, renderer);
	m_srcRect = { 0, 0, 0, 0 };
	m_dstRect = { 0, 0, 0, 0 };

	m_type = GameObjectType::TYPE_NONE;
	m_isDead = false;
	x = 0;
	y = 0;
}

GameObject::~GameObject()
{
}

void GameObject::Update(float dT)
{
	dT;
	x++;
	y = 0;

	m_srcRect = { 0, 0, 16, 16 };
	m_dstRect = { x, y, m_srcRect.w * 2, m_srcRect.h * 2 };
}

void GameObject::Render()
{
	SDL_RenderCopy(m_objRenderer, m_objTexture, nullptr, &m_dstRect);
}
