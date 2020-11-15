#pragma once

#include <SFML/Graphics.hpp>

class ObjectEditor;
#include "ObjectEditor.h"
#include "ResourceManager.h"

class GameObject {
public:
	GameObject(std::shared_ptr<ResourceManager> resourceManager)
	: position(0, 0), size(100, 100), colour(sf::Color::White), resourceManager(resourceManager) {};

	void Draw(sf::RenderWindow& window);
	void Update(ObjectEditor* editor);

	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color colour;

	int texIndex = 0;
	bool isDirty = true;
private:
	sf::RectangleShape rect;
	std::shared_ptr<ResourceManager> resourceManager;
};
