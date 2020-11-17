#pragma once

#include <vector>
#include <string>
#include <memory>

#include "GameObject.h"
#include "ResourceManager.h"

class ObjectEditor {
public:
	explicit ObjectEditor(std::shared_ptr<ResourceManager> resourceManager);

	void Update(GameObject* target);
private:
	bool keepSquare = true;

	std::shared_ptr<ResourceManager> resourceManager;
};