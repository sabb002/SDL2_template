#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

enum GameState {PLAY,EXIT};

class Game{
    public:
    Game(const char* title, int x, int y, int width, int height,Uint32 flags);
    ~Game();

    SDL_Texture* loadTexture(const char *filePath);

    void render(SDL_Texture* texture);
    void run();

    GameState _gameState;

    private:
        void clear();
        void display();
        void cleanUp();
        SDL_Window *_window;
        SDL_Renderer *_renderer; 

};