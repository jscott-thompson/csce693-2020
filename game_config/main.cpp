
#include "Game.hpp"
#include "lua.hpp"
#include <iostream>
#include <memory>
#include <string>


int main() {

   std::cout << "Creating game" << std::endl;
   auto game = std::make_unique<Game>(std::string{"config.lua"});

   std::cout << "Starting game loop" << std::endl;
   while (game->running()) {
      game->handle_events();
      game->update();
      game->render();
   }

   return 0;
}

