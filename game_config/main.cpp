
#include "Game.hpp"
#include "lua.hpp"
#include <iostream>

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

int main() {

   std::cout << "Creating game" << std::endl;
   Game* game = new Game();

   int xpos, ypos, width, height = 0;
   bool fullscreen = false;

   // use the configuration info available in the config.lua script
   lua_State* L{luaL_newstate()};
   //open all libraries
   luaL_openlibs(L);
   //load the config file
   luaL_dofile(L, "config.lua");
   //get all values from the file
   xpos = getIntField(L, "xpos");
   ypos = getIntField(L, "ypos");
   width = getIntField(L, "width");
   height = getIntField(L, "height");
   fullscreen = getBoolField(L, "fullscreen");

   //if a -1 one is returned I am assuming something went wrong with reading the file
   if(xpos == -1 || ypos == -1 || width == -1 || height == -1)
      game->init("1st Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
   else
      game->init("1st Game", xpos, ypos, width, height, fullscreen);

   std::cout << "Starting game loop" << std::endl;
   while (game->running()) {
      game->handle_events();
      game->update();
      game->render();
   }

   game->clean();
   return 0;
}

