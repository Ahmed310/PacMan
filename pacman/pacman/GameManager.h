#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SDL.h>
#include <SDL_ttf.h>

#include "Player.h"
#include "Level.h"
#include "Enemy.h"


#include<iostream>
#include<string.h>
#include<sstream>    // used to convert int to char*

class GameManager
{
public:
	GameManager();
	~GameManager();

	static GameManager* getInstance();
	void Init();
	void Draw(SDL_Surface* screen);
	void Update();
	void Dispose();          // release all variables made with new keyword in this method
	bool Intersect(SDL_Rect r1, SDL_Rect r2);
	void DrawText(SDL_Surface* screen, int x, int y, const char* str, TTF_Font* font);
	void DrawText(SDL_Surface* screen, int x, int y, int data, TTF_Font* font);


public:
	SDL_Surface* spriteSheet;           // this image contains all sprites
	SDL_Surface* textSurface;
	TTF_Font * font;					// small font 
	TTF_Font * font2;					// large font

	bool running = true;
	const int blockWidth = 32;
	const int blockHeight = 32;

	// here declare Each game object
	Player pacMan;
	Enemy ghost[4];
	Level _level;


	bool powerUp = false;					// when true ghosts becomes blue
	int previousIndex = -1;

	int totalFood = 0;
	//blocks types
	const int none = 0;
	const int solid = 1;
	const int player = 2;// later add more types
	const int ghostR = 3;   // red ghost
	const int power = 4;
	const int food = 5;
	const int ghostB = 6;
	const int ghostP = 7;
	const int ghostG = 8;
	
	
private:
	void ResetLevel();
	enum State { mainMenu, play, gameover, winScreen };
	State GameState = mainMenu;
	void OnPlayScreen();
	void OnMainMenu();
	void OnWinScreen();
	void OnGameOver();

	const int powerUpTime = 5;    // used when player is power up       
	float timer = 0.0f;


	SDL_Rect playBtnBound;
};

#endif // GAMEMANAGER_H
