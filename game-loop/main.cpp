
#include "Game.hpp"

#include <iostream>

Game* game{};

int main() {

   std::cout << "Starting game loop\n";
   game = new Game();

   game->init("1st Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

   while (game->running()) {
      game->handle_events();
      game->update();
      game->render();
   }

   game->clean();
   return 0;
}

