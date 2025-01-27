#pragma once

#include <vector>

#include "raylib.h"
#include "Particle.h"



class Firework
{

public:
	Firework(Vector2 startPos, float deltaTime);
	~Firework();


	void InitFirework();
	void update(float deltaTime);
	void draw();

	bool exploded;
	std::vector<Particle*> particles;
	float deltaTime;


private:

	Color colors[11] = { RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, PINK, GOLD, MAROON, MAGENTA, LIME };
	const int maxParticles = 50;
	Vector2 position;

};

