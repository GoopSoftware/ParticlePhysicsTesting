#include "Shotgun.h"


Shotgun::Shotgun() {

}

Shotgun::~Shotgun() {

	for (Particle* b : bullets) {
		delete b;
	}

}

void Shotgun::fire(Vector2 playerPos, Vector2 mousePos) {

	float spreadAngle = 15.f;
	float speed = 1000.f;
	float maxSpread = spreadAngle / 2.f;


	Vector2 direction = { mousePos.x - playerPos.x, mousePos.y - playerPos.y };
	float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0) {
		direction.x /= length;
		direction.y /= length;
	}

	for (int i = 0; i < maxBullets; i++) {
		Vector2 spreadDirection = direction;

		float angleOffset = (rand() % 3001 - 1500) / 10000.0f * 0.3f;
		float angle = atan2(spreadDirection.y, spreadDirection.x) + angleOffset;
		
		direction.x = cos(angle);
		direction.y = sin(angle);

		Vector2 bulletVelocity = { spreadDirection.x * speed, spreadDirection.y * speed };
		bullets.push_back(new Particle(playerPos, bulletVelocity, 1.0f, DARKGRAY));
	}
}


void Shotgun::update(float deltaTime) {
	for (auto& bullet : bullets) {
		bullet->update(deltaTime);
	}

	bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Particle* b) {return !b->isAlive();}), bullets.end());
}

void Shotgun::draw() {
	for (auto& bullet : bullets) {
		bullet->draw();
	}
}