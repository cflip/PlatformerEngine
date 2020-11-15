#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

class ResourceManager {
public:
	ResourceManager();

	std::shared_ptr<sf::Texture> GetTexture(size_t index);
	std::vector<std::pair<std::string, std::shared_ptr<sf::Texture>>>* GetTextureList();
private:
	std::vector<std::pair<std::string, std::shared_ptr<sf::Texture>>> textures;
};