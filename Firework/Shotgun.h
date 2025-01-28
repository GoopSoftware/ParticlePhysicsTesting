#pragma once

#include "Weapon.h"
#include "Particle.h"
#include <vector>


class Shotgun : public Weapon
{

public:

	Shotgun();
	~Shotgun();

	void fire(Vector2 playerPos, Vector2 mousePos) override;
	void update(float deltaTime) override;
	void draw();
	std::vector<Particle*> bullets;


private:

	int maxBullets = 6;

};

