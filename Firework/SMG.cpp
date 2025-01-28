#include "SMG.h"


SMG::SMG() {

}

SMG::~SMG() {
	
	for (Particle* b : bullets) {
		delete b;
	}
}

void SMG::fire(Vector2 playerPos, Vector2 mousePos) {

	Vector2 direction = { mousePos.x - playerPos.x, mousePos.y - playerPos.y };
	float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0) {
		direction.x /= length;
		direction.y /= length;
	}

	float speedOffset = (rand() % 700 + 1000);
	Vector2 bulletVelocity = { direction.x * speedOffset, direction.y * speedOffset };
	bullets.push_back(new Particle(playerPos, bulletVelocity, 1.f, DARKGRAY));
}

void SMG::update(float deltaTime) {
	for (auto& bullet : bullets) {
		bullet->update(deltaTime);
	}

	bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Particle* b) {return !b->isAlive();}), bullets.end());
}

void SMG::draw() {
	for (auto& bullet : bullets) {
		bullet->draw();
	}
}