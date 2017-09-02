#pragma once
#include <sdl\SDL.h>
#include <glew\glew.h>
#include "GLS_Program.h"
#include "Sprite.h"

enum class GameState {
	PLAY, EXIT
};

class CMainGame
{

private:
	int _width;
	int _height;
	void init();
	CGLS_Program _program;
	SDL_Window* _window;
	CSprite _sprite;
	void proccesInput();
	void initShaders();

public:
	CMainGame();
	~CMainGame();
	GameState _gameState;
	
	void run();
	void draw();
	void update();
};

