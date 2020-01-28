
#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "SDL2/SDL.h"
#include "sol/sol.hpp"
#include <string>

// class sol::state;

class Game {

public:
   Game() = default;
   ~Game();
   Game(const std::string config_file, const std::string logic_file);

   void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
   void init_logic(const std::string logic_file);
   void handle_events();
   void update();
   void render();

   bool running()                { return is_running; }

private:
   int counter{};
   bool is_running{};
   SDL_Window* window{};
   SDL_Renderer* renderer{};
   sol::state lua;
   sol::function user_logic;
};

#endif
