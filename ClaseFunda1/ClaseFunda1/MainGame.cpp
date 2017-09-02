#include "MainGame.h"
#include <iostream>
#include "Error.h"

using namespace std;


CMainGame::CMainGame() : _window(nullptr), _width(800),_height(600),_gameState(GameState::PLAY)
{
}

void CMainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow("Hola", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_OPENGL);
	if (_window == nullptr) {
		fatalError("SDL_Window was not loaded");
	}
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("GLEW was not loaded");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //pintar dos pantalla
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); //pintar la pantalla R V A TRANSP
	initShaders();
}

void CMainGame::initShaders() {

}
void CMainGame::update() {
	while (_gameState != GameState::EXIT) {
		draw();
		proccesInput();
	}
}
void CMainGame::draw() {

	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);
	//draw elements
	SDL_GL_SwapWindow(_window);

}
void CMainGame::proccesInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			cout << "x:" <<event.motion.x << "y:" << event.motion.y << endl;
			break;
		}
	}
}
void CMainGame::run() {
	init();
	update();
	_sprite.init(-1, -1, 1, 1);
}
CMainGame::~CMainGame()
{
}
