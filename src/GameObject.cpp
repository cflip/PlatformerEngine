#include "GameObject.h"

void GameObject::Draw(sf::RenderWindow& window) {
	window.draw(rect);
}

void GameObject::Update(ObjectEditor* editor) {
	if (editor != nullptr) {
		editor->Update(this);

		// TODO: Create some sort of texture manager rather than having the textures managed by the editor
		if (isDirty) {
			rect.setTexture(editor->GetTexture(texIndex).get(), true);
		}
	}

	if (isDirty) {
		rect.setPosition(position);
		rect.setSize(size);
		rect.setFillColor(colour);

		isDirty = false;
	}
}
