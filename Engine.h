#pragma once
#include <SDL2/SDL.h>
#include <GL/glew.h>

enum class GameState {PLAY, EXIT};

class Engine
{
public:
    Engine();
    ~Engine();

    void run();

private:
    void init();
    void loop();
    void input();
    void draw();

    SDL_Window* _pWindow;
    int _sWidth;
    int _sHeight;
    GameState _gameState;
};