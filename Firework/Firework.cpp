#include "Firework.h"


Firework::Firework(Vector2 startPos, float deltaTime) :
position(startPos), exploded(false)
{

	InitFirework();

}

Firework::~Firework() {
	
	for (Particle* p : particles) {
		delete p;
	}
}


void Firework::InitFirework() {

	if (!exploded) {
		for (int i = 0; i < maxParticles; i++) {
			float angle = static_cast<float>(GetRandomValue(0, 360) * DEG2RAD);
			float speed = static_cast<float>(GetRandomValue(8000, 30000) / 100);
			Vector2 velocity = { cos(angle) * speed, sin(angle) * speed };
			//int gravity = 2000;

			//velocity.x += gravity;
			Color color = colors[GetRandomValue(0, 10)];
			float lifetime = static_cast<float>(GetRandomValue(1, 4));

			particles.push_back(new Particle(position, velocity, lifetime, color));
		}
		exploded = true;
	}
}

void Firework::update(float deltaTime) {
	for (auto& particle : particles) {
		particle->update(deltaTime);
	}

	particles.erase(std::remove_if(particles.begin(), particles.end(), [](Particle* p) {return !p->isAlive();}), particles.end());

}

void Firework::draw() {
	for (auto& particle : particles) {
		particle->draw();
	}
}