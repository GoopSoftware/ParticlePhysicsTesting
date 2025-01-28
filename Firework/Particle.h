#pragma once

#include "raylib.h"
#include <iostream>
#include <random>


class Particle
{

public:

	Particle(Vector2 pos, Vector2 vel, float life, Color col);
	~Particle();


	void update(float detlaTime);
	void draw();

	bool isAlive() const { return lifespan > 0; }
	void cleanup(std::vector<Particle*> particles);
	float lifespan;


private:

	Vector2 position;
	Vector2 velocity;
	Color color;
	int particleSize;


};

