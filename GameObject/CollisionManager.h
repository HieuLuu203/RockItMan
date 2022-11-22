#pragma once
#include "HitBox.h"
#include "HitBox2.h"

class CollisionManager {
public:
	void addObj(HitBoxBase* hitBox);
	bool checkCollision(HitBoxBase* a, HitBoxBase* b);
	void Update();
private:
	std::list<HitBoxBase*> m_listObj;
};