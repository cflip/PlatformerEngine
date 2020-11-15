#include "GameObject.h"

void GameObject::Draw(sf::RenderWindow& window) {
	window.draw(rect);
}

void GameObject::Update(ObjectEditor* editor) {
	if (editor != nullptr) {
		editor->Update(this);
	}

	if (isDirty) {
		// TODO: This will update the texture every time there is a change made in the editor
		// It should only change the texture when it really needs to
		rect.setTexture(resourceManager->GetTexture(texIndex).get(), true);

		rect.setPosition(position);
		rect.setSize(size);
		rect.setFillColor(colour);

		isDirty = false;
	}
}
