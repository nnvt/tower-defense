#pragma once
#include <vector>
#include <chrono>
#include <memory>
#include <SDL.h>
#include "Unit.h"
#include "Level.h"
#include "Timer.h"



class Game
{
private:
	enum class PlacementMode {
		wall,
		units
	} placementModeCurrent;


public:
	Game(SDL_Window* window, SDL_Renderer* renderer, int windowWidth, int windowHeight);
	~Game();


private:
	void processEvents(SDL_Renderer* renderer, bool& running);
	void update(SDL_Renderer* renderer, float dT);
	void updateSpawnUnitsIfRequired(SDL_Renderer* renderer, float dT);
	void draw(SDL_Renderer* renderer);
	void addUnit(SDL_Renderer* renderer, Vector2D posMouse);
	void removeUnitsAtMousePosition(Vector2D posMouse);

	int mouseDownStatus = 0;

	const int tileSize = 64;
	Level level;
	
	std::vector<Unit> listUnits;

	SDL_Texture* textureOverlay = nullptr;
	bool overlayVisible = true;

	Timer spawnTimer, roundTimer;
	int spawnUnitCount = 0;
};