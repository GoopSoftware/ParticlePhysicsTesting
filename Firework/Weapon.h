#pragma once


#include "particle.h"
#include "raylib.h"



class Weapon
{

public:

	virtual void fire(Vector2 playerPos, Vector2 mousePos) {};
	virtual void update(float deltaTime) = 0;
	virtual void draw() = 0;
	virtual std::vector<Particle*> getBullets() = 0;

	virtual ~Weapon() {};



private:


};

