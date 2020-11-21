#include "ResourceManager.h"

#include <iostream>
#ifdef __has_include                        
	#if __has_include(<filesystem>)
		#include <filesystem>
		namespace fs = std::filesystem;
	#elif __has_include(<experimental/filesystem>)
		#include <experimental/filesystem>
		namespace fs = std::experimental::filesystem;
	#else
		#error "This project requires the std::filesystem library"
	#endif
#endif

ResourceManager::ResourceManager() {
	textures.emplace_back("[no texture]", nullptr);

	fs::path resPath("res/");
	if (fs::exists(resPath)) {
		for (const auto& entry : fs::directory_iterator(resPath)) {
			std::string path = entry.path().string();

			std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
			if (!texture->loadFromFile(path)) {
				std::cout << "Can't read image from " << path << "\n";
				continue;
			}

			textures.emplace_back(path, texture);
		}
	}
}

std::shared_ptr<sf::Texture> ResourceManager::GetTexture(size_t index) {
	return textures[index].second;
}

std::vector<std::pair<std::string, std::shared_ptr<sf::Texture>>>* ResourceManager::GetTextureList() {
	return &textures;
}
