
#include <headers/game.h>

Game::Game(const char* title, int x, int y, int width, int height,Uint32 flags){
    SDL_Init(SDL_INIT_EVERYTHING);

    _window = SDL_CreateWindow(title,x,y,width,height,flags);
    _renderer = SDL_CreateRenderer(_window,-1,SDL_RENDERER_ACCELERATED);
};

Game::~Game(){};

void Game::run(){
    display();
    clear();
}

SDL_Texture* Game::loadTexture(const char* filePath){

    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(_renderer, filePath);

    if(texture == NULL){
        std::cout << "File Path incorrect!\n"
                  << SDL_Error;
    }
    return texture;
}

void Game::render(SDL_Texture *texture){
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 179;
    src.h = 99;

    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;
    dest.w = 200;
    dest.h = 100;

    SDL_RenderCopy(_renderer, texture, &src, &dest);
}

void Game::display(){
    SDL_RenderPresent(_renderer);
};

void Game::clear(){
    SDL_RenderPresent(_renderer);
};

void Game::cleanUp(){
    SDL_DestroyWindow(_window);
}
