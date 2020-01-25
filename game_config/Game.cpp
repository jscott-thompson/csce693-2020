
#include "Game.hpp"
#include <iostream>
#include "lua.hpp"
#include <string>

//function that gets an int from a file based off the key
int getIntField(lua_State* L, const char* key) {
   lua_getglobal(L, key);

   //the result I want should be on the top of the stack
   if(lua_isnil(L, -1))
      return -1;
   else 
      return (int)lua_tonumber(L, -1);
   
}

//function that gets a bool from a file based off the key
bool getBoolField(lua_State* L, const char* key) {
   lua_getglobal(L, key);

   //the result I want should be on the top of the stack
   if(lua_isnil(L, -1))
      return false;
   else 
      return (bool)lua_toboolean(L, -1);
}

Game::Game(const std::string config_file) 
{
   int xpos, ypos, width, height = 0;
   bool fullscreen = false;

   // use the configuration info available in the config.lua script
   lua_State* L{luaL_newstate()};
   //open all libraries
   luaL_openlibs(L);
   //load the config file
   luaL_dofile(L, config_file.c_str());
   //get all values from the file
   xpos = getIntField(L, "xpos");
   ypos = getIntField(L, "ypos");
   width = getIntField(L, "width");
   height = getIntField(L, "height");
   fullscreen = getBoolField(L, "fullscreen");

      //if a -1 one is returned I am assuming something went wrong with reading the file
   if(xpos == -1 || ypos == -1 || width == -1 || height == -1)
      this->init("1st Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
   else
      this->init("1st Game", xpos, ypos, width, height, fullscreen);

}

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
   counter++;
   std::cout << counter << std::endl;
}

void Game::render()
{
   SDL_RenderClear(renderer);
   // this is where we would add stuff to render
   SDL_RenderPresent(renderer);
}

void Game::clean()
{
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   std::cout << "Game cleaned..." << std::endl;
}

Game::~Game()
{
   this->clean();

}
