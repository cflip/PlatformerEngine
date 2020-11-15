#pragma once

#include <SFML/Graphics.hpp>

class ObjectEditor;
#include "ObjectEditor.h"

class GameObject {
public:
	GameObject() : position(0, 0), size(100, 100), colour(sf::Color::White) {};

	void Draw(sf::RenderWindow& window);
	void Update(ObjectEditor* editor);

	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color colour;

	int texIndex = 0;
	bool isDirty = true;
private:
	sf::RectangleShape rect;
};
