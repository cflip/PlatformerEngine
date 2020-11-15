#include <imgui.h>

#include <iostream>
#include <memory>
#include <experimental/filesystem>

#include "ObjectEditor.h"

namespace fs = std::experimental::filesystem;

static bool getPathFromVector(void* vector, int index, const char** result) {
	auto& vec = *static_cast<std::vector<std::pair<std::string, std::shared_ptr<sf::Texture>>>*>(vector);

	if (index < 0 || index >= static_cast<int>(vec.size())) {
		return false;
	}

	*result = vec.at(index).first.c_str();
	return true;
};

ObjectEditor::ObjectEditor() {
	textures.push_back(std::make_pair("[no texture]", nullptr));

	fs::path resPath("res/");
	if (fs::exists(resPath)) {
		for (const auto& entry : fs::directory_iterator(resPath)) {
			std::string path = entry.path().string();

			std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
			if (!texture->loadFromFile(path)) {
				std::cout << "Can't read image from " << path << "\n";
				continue;
			}

			textures.push_back(std::make_pair(path, texture));
		}
	}
}

void ObjectEditor::Update(GameObject* target) {
	bool valueChanged = false;
	bool updateTexture = false;

	ImGui::Begin("Object Editor");
	ImGui::LabelText("Memory Location", "0x%X", this);
	valueChanged |= ImGui::SliderInt2("Position", pos, 0, 1000, "%dpx");

	valueChanged |= ImGui::Checkbox("Keep Square", &keepSquare);

	if (keepSquare) {
		valueChanged |= ImGui::SliderInt("Size", scale, 1, 700, "%dpx");
		scale[1] = scale[0];
	} else {
		valueChanged |= ImGui::SliderInt2("Size", scale, 1, 700, "%dpx");
	}

	valueChanged |= ImGui::ColorEdit3("Colour", col);

	if (textures.size() > 1) {
		updateTexture = ImGui::ListBox("Texture", &target->texIndex, getPathFromVector, static_cast<void*>(&textures), textures.size());
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

std::shared_ptr<sf::Texture> ObjectEditor::GetTexture(size_t index) {
	return textures[index].second;
}