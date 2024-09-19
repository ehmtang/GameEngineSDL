#pragma once

#include <vector>
#include "src/entities/GameObject.h"

template <typename T>
concept GameObjectable = std::is_base_of<GameObject, T>::value;

class GameObjectManager
{
public:
	static GameObjectManager& Instance()
	{
		static GameObjectManager instance;
		return instance;
	}

	// Prevent copy and copy assignment 
	GameObjectManager(const GameObjectManager&) = delete;
	GameObjectManager& operator= (GameObjectManager&) = delete;

	template<GameObjectable T, typename... Args>
	T* CreateGameObject(Args... args);

	void Update(float deltaTime);
	void PostUpdate();
	void Render();

private:
	
	// Private constructor and destructor to prevent instantiation and deletion
	GameObjectManager();
	~GameObjectManager();

	std::vector<GameObject*> m_pCreatedGameObjects;
	std::vector<GameObject*> m_pGameObjects;
};

template<GameObjectable T, typename... Args>
T* GameObjectManager::CreateGameObject(Args... args)
{
	T* newObj = new T(args ...);
	m_pGameObjects.push_back(newObj);
	return newObj;
}