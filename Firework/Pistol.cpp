#include "Pistol.h"

Pistol::Pistol() 
{

}

Pistol::~Pistol() {
	for (auto bullet : bullets) {
		delete bullet;
	}

}


void Pistol::fire(Vector2 playerPos, Vector2 mousePos) {
	

}

void Pistol::update(float deltaTime) {
	for (auto& bullet : bullets) {
		bullet->update(deltaTime);
	}

	bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Particle* b) {return b->isAlive();}), bullets.end());
}

void Pistol::draw() {
	for (auto& bullet : bullets) {
		bullet->draw();
	}
}

std::vector<Particle*> Pistol::getBullets() {
	return bullets;
}