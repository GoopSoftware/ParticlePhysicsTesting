#include <iostream>
#include "raylib.h"

#include "Firework.h"

#include "Weapon.h"
#include "Pistol.h"


/* ------------------  ToDo: --------------------
Figure out why particles will blink into existence

*/


enum class WeaponType {
	PISTOL,
	SHOTGUN
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
	std::vector<Particle*> bullets;
	//std::vector<Particle*> bullets = currentWeapon->getBullets();
	

	while (!WindowShouldClose()) {
		float deltaTime = GetFrameTime();


		if (IsKeyPressed(KEY_SPACE)) {
			Vector2 spawnPos = GetMousePosition();
			fireworks.push_back(new Firework(spawnPos, deltaTime));
		}
		if (IsKeyDown(KEY_A)) { playerPos.x -= 5; }
		if (IsKeyDown(KEY_D)) { playerPos.x += 5; }
		if (IsKeyDown(KEY_W)) { playerPos.y -= 5; }
		if (IsKeyDown(KEY_S)) { playerPos.y += 5; }

		if (IsKeyPressed(KEY_ONE)) {
			if (currentWeaponType != WeaponType::PISTOL) {
				currentWeaponType = WeaponType::PISTOL;
				delete currentWeapon;
				currentWeapon = new Pistol();
			}
		}
		if (IsKeyPressed(KEY_TWO)) {
			if (currentWeaponType != WeaponType::SHOTGUN) {
				currentWeaponType = WeaponType::SHOTGUN;
				delete currentWeapon;
				//currentWeapon = new Shotgun();
			}
		}
		
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			Vector2 mousePos = GetMousePosition();	
			Vector2 direction = { mousePos.x - playerPos.x, mousePos.y - playerPos.y };
			float length = sqrt(direction.x * direction.x + direction.y * direction.y);
			if (length != 0) {
				direction.x /= length;
				direction.y /= length;
			}
			std::cout << "FIRING" << std::endl;
			Vector2 bulletVelocity = { direction.x * 600.f, direction.y * 600.f };
			if (currentWeaponType == WeaponType::PISTOL) {
				bullets.push_back(new Particle(playerPos, bulletVelocity, 2.5f, DARKGRAY));
			}
		}


		for (auto& firework : fireworks) {
			firework->update(deltaTime);
		}

		for (auto& bullet : bullets) {
			bullet->update(deltaTime);
		}


		fireworks.erase(std::remove_if(fireworks.begin(), fireworks.end(), [](Firework* f) {return f->particles.empty();}), fireworks.end());
		bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Particle* p) {return !p->isAlive();}), bullets.end());


		BeginDrawing();
		ClearBackground(RAYWHITE);
		// Graphic Rendering

		DrawRectangle(playerPos.x - 12.5f, playerPos.y - 12.5f, 25, 25, BLUE);

		for (auto& firework : fireworks) {
			firework->draw();
		}

		for (auto& bullet : bullets) {
			bullet->draw();
		}


		EndDrawing();

	}

	delete currentWeapon;

	for (auto& firework : fireworks) {
		delete firework;
	}

	for (auto& bullet : bullets) {
		delete bullet;
	}

	
	CloseWindow();
	
	return 0;
}