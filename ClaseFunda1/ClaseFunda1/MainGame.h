#pragma once
#include <sdl\SDL.h>
#include <glew\glew.h>

enum class GameState {
	PLAY, EXIT
};

class CMainGame
{

private:
	int _width;
	int _height;
	void init();
	SDL_Window* _window;
	void proccesInput();

public:
	CMainGame();
	~CMainGame();
	GameState _gameState;
	
	void run();
	void draw();
	void update();
};

