#include "CollisionManager.h"

void CollisionManager::addObj(HitBoxBase* hitBox)
{
    m_listObj.push_back(hitBox);
}

bool CollisionManager::checkCollision(HitBoxBase* a, HitBoxBase* b)
{
    HitBox2* c1;
    HitBox2* c2;
    //c = new HitBox();
    HitBox* d1;
    HitBox* d2;
    //d = new HitBox2();
    if (a->checkCircle())
    {
        c1 = (HitBox2*)a;
        if (b->checkCircle())
        {
            c2 = (HitBox2*)b;
            return c1->getGlobalBounds().intersects(c2->getGlobalBounds());

        }
        else
        {
            d1 = (HitBox*)b;
            return c1->getGlobalBounds().intersects(d1->getGlobalBounds());
        }
    }
    else
    {
        d1 = (HitBox*)a;
        if (b->checkCircle())
        {
            c2 = (HitBox2*)b;
            return d1->getGlobalBounds().intersects(c2->getGlobalBounds());

        }
        else
        {
            d1 = (HitBox*)b;
            return d1->getGlobalBounds().intersects(d1->getGlobalBounds());
        }
    }

}

void CollisionManager::Update()
{
    for (auto a : m_listObj) {
        if (a->isAlive() == false) continue;
        for (auto b : m_listObj) {
            if (b->isAlive() == false) continue;

            if (a->getTag() == b->getTag()) continue;
            if (!checkCollision(a, b)) continue;

            if (a->getTag() == PLAYER && b->getTag() == BOMB) {
                a->setAlive(false);
                b->setAlive(false);
            }

            if (a->getTag() == PLAYER && b->getTag() == TRAP) {
                a->setAlive(false);
                //b->setAlive(false);
            }

            if (a->getTag() == PLAYER && b->getTag() == MANA) {
                a->setAddMana(true);
                b->setAlive(false);
            }

            if (a->getTag() == PLAYER && b->getTag() == COIN) {
                a->setAddScore(true);
                b->setAlive(false);
            }

                if (a->getTag() == TRAP && b->getTag() == BOMB) {
                    b->setAlive(false);
            }
        }
    }
}