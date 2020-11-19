#include "GameObject.h"

GameObject::GameObject(std::shared_ptr<ResourceManager> resourceManager)
		: position(0, 0), size(100, 100), colour(sf::Color::White), resourceManager(std::move(resourceManager)) {
	Update();
}

void GameObject::Draw(sf::RenderWindow& window) {
	window.draw(rect);
}

void GameObject::Update() {
	if (isDirty) {
		// TODO: This will update the texture every time there is a change made in the editor
		// It should only change the texture when it really needs to
		rect.setTexture(resourceManager->GetTexture(texIndex).get(), true);

		rect.setPosition(position);
		rect.setSize(size);
		rect.setFillColor(colour);

		isDirty = false;
	}

	if (isSelected) {
		rect.setOutlineColor(sf::Color::Green);
		rect.setOutlineThickness(2.f);
	} else {
		rect.setOutlineThickness(0.f);
	}
}

bool GameObject::WithinBounds(int x, int y) const {
	return x >= int(position.x) && y >= int(position.y) && x < int(position.x + size.x) && y < int(position.y + size.y);
}
