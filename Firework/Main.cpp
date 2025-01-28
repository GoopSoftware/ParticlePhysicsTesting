#include <iostream>
#include "raylib.h"
#include "raymath.h"

#include "Firework.h"

#include "Weapon.h"
#include "Pistol.h"
#include "Shotgun.h"
#include "SMG.h"

/* ------------------  ToDo: --------------------
Figure out why particles will blink into existence

*/


enum class WeaponType {
	PISTOL,
	SHOTGUN,
	SMG
};


int main() {


	const int screenWidth = 1280;
	const int screenHeight = 720;

	Vector2 playerPos = { 100, screenHeight / 2 };


	InitWindow(screenWidth, screenHeight, "Particle Physics");
	SetTargetFPS(60);

	Weapon* currentWeapon = new Pistol();
	WeaponType currentWeaponType = WeaponType::PISTOL;

	std::vector<Firework*> fireworks;

	

	while (!WindowShouldClose()) {
		float deltaTime = GetFrameTime();


		if (IsKeyPressed(KEY_SPACE)) {
			Vector2 spawnPos = GetMousePosition();
			fireworks.push_back(new Firework(spawnPos, deltaTime));
		}

		Vector2 movement = { 0, 0 };

		if (IsKeyDown(KEY_A)) { movement.x -= 5; }
		if (IsKeyDown(KEY_D)) { movement.x += 5; }
		if (IsKeyDown(KEY_W)) { movement.y -= 5; }
		if (IsKeyDown(KEY_S)) { movement.y += 5; }

		if (movement.x != 0 || movement.y != 0) { 
			movement = Vector2Normalize(movement);
		}

		playerPos.x += movement.x * 5;
		playerPos.y += movement.y * 5;


		if (IsKeyPressed(KEY_ONE)) {
			if (currentWeaponType != WeaponType::PISTOL) {
				currentWeaponType = WeaponType::PISTOL;
				delete currentWeapon;
				currentWeapon = new Pistol();
			}
		}
		if (IsKeyPressed(KEY_TWO)) {
			if (currentWeaponType != WeaponType::SMG) {
				currentWeaponType = WeaponType::SMG;
				delete currentWeapon;
				currentWeapon = new SMG();
			}
		}
		if (IsKeyPressed(KEY_THREE)) {
			if (currentWeaponType != WeaponType::SHOTGUN) {
				currentWeaponType = WeaponType::SHOTGUN;
				delete currentWeapon;
				currentWeapon = new Shotgun();
			}
		}
		
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			if (currentWeaponType == WeaponType::SMG) {
				currentWeapon->fire(playerPos, GetMousePosition());
			}
			else {
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					currentWeapon->fire(playerPos, GetMousePosition());

				}
			}
		
		}


		for (auto& firework : fireworks) {
			firework->update(deltaTime);
		}

		currentWeapon->update(deltaTime);


		fireworks.erase(std::remove_if(fireworks.begin(), fireworks.end(), [](Firework* f) {return f->particles.empty();}), fireworks.end());


		BeginDrawing();
		ClearBackground(RAYWHITE);
		// Graphic Rendering

		DrawRectangle(playerPos.x - 12.5f, playerPos.y - 12.5f, 25, 25, BLUE);

		for (auto& firework : fireworks) {
			firework->draw();
		}
		currentWeapon->draw();

		EndDrawing();

	}

	delete currentWeapon;

	for (auto& firework : fireworks) {
		delete firework;
	}

	
	CloseWindow();
	
	return 0;
}