
#define SOL_ALL_SAFETIES_ON 1
#include "Game.hpp"
#include <iostream>
#include "sol/sol.hpp"
#include <string>

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
   Uint32 flags{};
   if (fullscreen) {
      flags = SDL_WINDOW_FULLSCREEN;
   }

   if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
      std::cout << "Subsystems initialized..." << std::endl;
      window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
      if (window) {
         std::cout << "Window created..." << std::endl;
      }
      renderer = SDL_CreateRenderer(window, -1, 0);
      if (renderer) {
         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
         std::cout << "Renderer created..." << std::endl;
      }
   is_running = true;
   } else {
      is_running = false;
   }
}

void Game::init_logic(const std::string logic_file)
{
   lua.script_file(logic_file);
}

Game::~Game()
{
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
   std::cout << "Game cleaned..." << std::endl;
}

void Game::handle_events()
{
   SDL_Event event;
   SDL_PollEvent(&event);
   switch (event.type) {
      case SDL_QUIT:
         is_running = false;
         break;
      default:
         break;
   }
}

void Game::update()
{
   // call Lua's function update() to increment a counter
   // and print the returned value
   std::cout << static_cast<int>( lua["update"]() ) << std::endl;
}

void Game::render()
{
   SDL_RenderClear(renderer);
   // this is where we would add stuff to render
   SDL_RenderPresent(renderer);
}

