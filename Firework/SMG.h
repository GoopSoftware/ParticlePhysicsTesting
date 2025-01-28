#pragma once

#include "Weapon.h"
#include "Particle.h"
#include <vector>


class SMG : public Weapon
{

public:

	SMG();
	~SMG();

	void fire(Vector2 playerPos, Vector2 mousePos) override;
	void update(float deltatime) override;
	void draw() override;
	std::vector<Particle*> bullets;

private:




};

