#pragma once

#include <SFML/Graphics.hpp>
#include <utility>

#include "ResourceManager.h"

class GameObject {
public:
	explicit GameObject(std::shared_ptr<ResourceManager> resourceManager);

	void Draw(sf::RenderWindow& window);
	void Update();
	bool WithinBounds(int x, int y) const;

	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color colour;

	int texIndex = 0;
	bool isDirty = true;
private:
	sf::RectangleShape rect;
	std::shared_ptr<ResourceManager> resourceManager;
};
