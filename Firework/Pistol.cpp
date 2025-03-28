#include "Pistol.h"

Pistol::Pistol() 
{

}

Pistol::~Pistol() {

	for (Particle* b : bullets) {
		delete b;
	}

}


void Pistol::fire(Vector2 playerPos, Vector2 mousePos) {

	Vector2 direction = { mousePos.x - playerPos.x, mousePos.y - playerPos.y };
	float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0) {
		direction.x /= length;
		direction.y /= length;
	}

	float speed = 2500.f;
	Vector2 bulletVelocity = { direction.x * speed, direction.y * speed };
	bullets.push_back(new Particle(playerPos, bulletVelocity, 1.f, DARKGRAY));
}

void Pistol::update(float deltaTime) {
	for (auto& bullet : bullets) {
		bullet->update(deltaTime);
	}

	bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Particle* b) {return !b->isAlive();}), bullets.end());
}

void Pistol::draw() {
	for (auto& bullet : bullets) {
		bullet->draw();
	}
}