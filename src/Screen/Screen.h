#ifndef _SCREEN_H
#define _SCREEN_H
#define SDL_MAIN_HANDLED 
#include "SDL.h"

namespace particleScreen{

    class Screen{
        
        public : 
            const static int SCREEN_WIDTH = 1000;
            const static int SCREEN_HEIGHT = 1000;

        private : 
            SDL_Window* window;
            SDL_Renderer* renderer;
            SDL_Texture* texture;

            Uint32 *buffer = NULL;

        public :

            Screen(); //Constructor

            bool init();
            bool processEvents();
            void close();
            void update();
            void clear();
            void setPixel(int x, int y,  Uint8 red, Uint8 green, Uint8 blue);

        protected : 

    }; 



}

#endif