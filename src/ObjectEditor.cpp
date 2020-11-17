#include <imgui.h>

#include <iostream>
#include <memory>
#include <utility>

#include "ObjectEditor.h"

static bool getPathFromVector(void* vector, int index, const char** result) {
	auto& vec = *static_cast<std::vector<std::pair<std::string, std::shared_ptr<sf::Texture>>>*>(vector);

	if (index < 0 || index >= static_cast<int>(vec.size())) {
		return false;
	}

	*result = vec.at(index).first.c_str();
	return true;
}

ObjectEditor::ObjectEditor(std::shared_ptr<ResourceManager> resourceManager) : resourceManager(std::move(resourceManager)) {}

void ObjectEditor::Update(GameObject* target) {
	bool valueChanged = false;
	bool updateTexture = false;

	ImGui::Begin("Object Editor");
	if (target == nullptr) {
		ImGui::Text("Left-click on an object to select it, \nright-click to deselect.");
		ImGui::End();
		return;
	}

	// TODO: Create helper functions so this is not needed
	float col[3] = { target->colour.r / 255.f, target->colour.g / 255.f, target->colour.b / 255.f };
	int pos[2] = { (int) target->position.x, (int) target->position.y };
	int scale[2] = { (int) target->size.x, (int) target->size.y };

	ImGui::LabelText("Memory Location", "0x%X", target);
	valueChanged |= ImGui::SliderInt2("Position", pos, 0, 1000, "%dpx");

	valueChanged |= ImGui::Checkbox("Keep Square", &keepSquare);

	if (keepSquare) {
		valueChanged |= ImGui::SliderInt("Size", scale, 1, 700, "%dpx");
		scale[1] = scale[0];
	} else {
		valueChanged |= ImGui::SliderInt2("Size", scale, 1, 700, "%dpx");
	}

	valueChanged |= ImGui::ColorEdit3("Colour", col);

	auto textures = resourceManager->GetTextureList();

	if (textures->size() > 1) {
		updateTexture = ImGui::ListBox("Texture", &target->texIndex, getPathFromVector, static_cast<void*>(textures), textures->size());
	} else {
		ImGui::Text("Place images in a res/ folder to see them here");
	}

	ImGui::End();

	if (valueChanged || updateTexture) {
		target->position = sf::Vector2f(pos[0], pos[1]);
		target->size = sf::Vector2f(scale[0], scale[1]);
		target->colour = sf::Color(col[0] * 255.f, col[1] * 255.f, col[2] * 255.f);
		target->isDirty = true;
	}
}
