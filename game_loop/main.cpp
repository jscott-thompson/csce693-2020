
#include "Game.hpp"

#include <iostream>
#include <memory>

int main() {

   std::cout << "Creating game" << std::endl;
   std::unique_ptr<Game> game = std::make_unique<Game>();

   game->init("1st Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

   std::cout << "Starting game loop" << std::endl;
   while (game->running()) {
      game->handle_events();
      game->update();
      game->render();
   }

   game->clean();
   return 0;
}

