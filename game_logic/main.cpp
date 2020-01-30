
#include "Game.hpp"
#include "lua.hpp"
#include <iostream>
#include <memory>
#include <string>


int main() {

   std::cout << "Creating game" << std::endl;
   auto game = std::make_unique<Game>("1st Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

   std::cout << "Initializing logic" << std::endl;
   game->init_logic(std::string{"logic.lua"});

   std::cout << "Starting game loop" << std::endl;
   while (game->running()) {
      game->handle_events();
      game->update();
      game->render();
   }

   std::cout << "Game complete" << std::endl;

   return 0;
}

