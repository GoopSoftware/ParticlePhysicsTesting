#include "Particle.h"


Particle::Particle(Vector2 pos, Vector2 vel, float life, Color col) :
	position(pos), velocity(vel), lifespan(life), color(col), particleSize(5)
{

}

Particle::~Particle() {

}

void Particle::update(float deltaTime) {

	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;
	lifespan -= 1 * deltaTime;
	//std::cout << "X: " << position.x << " " << "Y: " << position.y << std::endl;
	//std::cout << lifespan << std::endl;
	color.a = static_cast<int>(255 * (lifespan * 60.f));


}

void Particle::draw() {
	if (lifespan > 0) {
		DrawCircleV(position, particleSize, color);
	}

}

void Particle::cleanup(std::vector<Particle*> particles) {
	if (lifespan <= 0) {
		delete this;
		particles.erase(std::remove(particles.begin(), particles.end(), this), particles.end());
	}
}
