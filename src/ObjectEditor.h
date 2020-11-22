#pragma once

#include <vector>
#include <string>
#include <memory>

#include <SFML/Graphics/Rect.hpp>

#include "GameObject.h"
#include "ResourceManager.h"

class ObjectEditor {
public:
	explicit ObjectEditor(std::shared_ptr<ResourceManager> resourceManager);

	void Update(GameObject* target, sf::FloatRect& windowSize);
private:
	bool keepSquare = true;

	std::shared_ptr<ResourceManager> resourceManager;
};