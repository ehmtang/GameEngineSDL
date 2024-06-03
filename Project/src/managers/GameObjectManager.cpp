#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	for (GameObject* obj : m_pCreatedGameObjects)
	{
		delete obj;
	}
	m_pCreatedGameObjects.clear();

	for (GameObject* obj : m_pGameObjects)
	{
		delete obj;
	}
	m_pGameObjects.clear();
}

void GameObjectManager::Update(float dT)
{
	for (GameObject* obj : m_pGameObjects)
	{
		if (!obj->IsDead())
		{
			obj->Update(dT);
		}
	}
}

void GameObjectManager::Render()
{
	for (GameObject* obj : m_pGameObjects)
	{
		if (!obj->IsDead())
		{
			obj->Render();
		}
	}
}
