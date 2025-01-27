#pragma once

#include "Weapon.h"
#include "Particle.h"
#include <Vector>


class Pistol : public Weapon 
{

public:

	Pistol();
	~Pistol();

	void fire(Vector2 playerPos, Vector2 mousePos) override;
	void update(float deltaTime) override;
	void draw() override;
	std::vector<Particle*> getBullets() override;


private:

	std::vector<Particle*> bullets;

};

