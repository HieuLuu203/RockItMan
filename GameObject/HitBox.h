#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitboxBase.h"

class HitBox :public sf::RectangleShape, public HitBoxBase {
public:
	HitBox();
	HitBox(Vector2i size);
	~HitBox();
};