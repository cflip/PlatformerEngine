#pragma once

#include <vector>
#include <string>
#include <memory>

class GameObject;
#include "GameObject.h"

class ObjectEditor {
public:
	ObjectEditor();

	void Update(GameObject* target);
	std::shared_ptr<sf::Texture> GetTexture(size_t index);
private:
	float col[3] = { 1, 1, 1 };
	int pos[2] = { 0, 0 };
	int scale[2] = { 100, 100 };
	bool keepSquare;

	std::vector<std::pair<std::string, std::shared_ptr<sf::Texture>>> textures;
};