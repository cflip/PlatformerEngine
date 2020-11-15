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
	float col[3] = { 1, 1, 1 };
	int pos[2] = { 0, 0 };
	int scale[2] = { 100, 100 };
	bool keepSquare = true;

	std::shared_ptr<ResourceManager> resourceManager;
};