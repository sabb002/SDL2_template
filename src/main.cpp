#include <headers/game.h>

int main(int argc, char* argv[]){

    int screenWidth = 1080;
    int screenHeight = 720;
    Uint32 flags =SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;

    Game game("MyGame",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screenWidth,screenHeight,flags);

    SDL_Texture *image = game.loadTexture("image.png");

    //Game Events
    while(game._gameState!= GameState::EXIT){
        SDL_Event e;
        SDL_PollEvent(&e);

        switch(e.type){
            case SDL_QUIT:
                game._gameState = GameState::EXIT;
                break;
        }

        game.render(image);
        game.run();
    }

    return 0;
}
