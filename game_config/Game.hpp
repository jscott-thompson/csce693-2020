
#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "SDL2/SDL.h"
#include <string>

class Game {

public:
   Game() = default;
   ~Game();
   Game(const std::string config_file);


   void handle_events();
   void update();
   void render();

   bool running()                { return is_running; }

private:
   int counter{};
   bool is_running{};
   SDL_Window* window{};
   SDL_Renderer* renderer{};
};

#endif
