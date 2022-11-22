#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitboxBase.h"

class HitBox2 :public sf::CircleShape, public HitBoxBase {
public:
	HitBox2();
	HitBox2(float size);
	~HitBox2();
};