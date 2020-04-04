#include "Engine.h"

#include <iostream>
#include <string>

void fatalError(std::string errorString)
{
    std::cout << errorString << std::endl;
    std::cout << "Enter any key to exit..." << std::endl;
    int temp;
    std::cin >> temp;
    SDL_Quit();
}

Engine::Engine()
{
    _pWindow = nullptr;
    _sWidth = 640;
    _sHeight = 480;
    _gameState = GameState::PLAY;
}

Engine::~Engine()
{

}

void Engine::run()
{
    init();
    loop();
}

void Engine::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    _pWindow = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _sWidth, _sHeight, SDL_WINDOW_OPENGL);
    if(_pWindow == nullptr)
    {
        fatalError("SDL Window could not be created!");
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(_pWindow);
    if(glContext == nullptr)
    {
        fatalError("SDL_GL context could not be created!");
    }

    GLenum error = glewInit(); 
    if(error != GLEW_OK)
    {
        fatalError("Could not initialize glew!");
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void Engine::loop()
{
    while(_gameState != GameState::EXIT)
    {
        input();
        draw();
    }
}

void Engine::input()
{
    SDL_Event evnt;
    
    while(SDL_PollEvent(&evnt))
    {
        switch (evnt.type)
        {
        case SDL_QUIT:
            _gameState = GameState::EXIT;
            break;
        case SDL_MOUSEMOTION:
            std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
            break;

        default:
            break;
        }
    }
}

void Engine::draw()
{
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnableClientState(GL_COLOR_ARRAY);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f( 0.0f, 0.5f);
    glVertex2f(-0.5f,-0.5f);
    glVertex2f( 0.5f, -0.5f);
    glEnd();

    SDL_GL_SwapWindow(_pWindow);
}