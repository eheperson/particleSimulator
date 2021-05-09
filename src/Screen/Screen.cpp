#include "Screen.h"
#include<iostream>
#include<string.h> //for memset()

using namespace std;

namespace particleScreen{

    // Constructor initialization list
    Screen :: Screen() : window(NULL), renderer(NULL), texture(NULL), buffer(NULL), buffer2(NULL){};

    /*----------------------------------------------------------------------------------*/  

    bool Screen :: init(){
            if(SDL_Init(SDL_INIT_VIDEO) < 0){
                cout << "SDL Init Failed !" << endl;
                return false;
            }
            else{
                cout << "SDL Init Succeed !" << endl;
            }
            /**/
            window = SDL_CreateWindow("Particle Animation",
                                                SDL_WINDOWPOS_UNDEFINED,
                                                SDL_WINDOWPOS_UNDEFINED,
                                                SCREEN_WIDTH,
                                                SCREEN_HEIGHT,
                                                SDL_WINDOW_SHOWN);
            if(window == NULL){
                SDL_Quit();
                return false;
            }
            /**/
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
                                        //(window to render, _, ensures our rendering syncronized without refresh)
            if (renderer == NULL){
                cout << "Could not create renderer !!" << endl;

                SDL_DestroyWindow(window);
                SDL_Quit();

                return false;
            }
            /**/
            texture = SDL_CreateTexture(renderer,
                                        SDL_PIXELFORMAT_RGBA8888,
                                        SDL_TEXTUREACCESS_STATIC,
                                        SCREEN_WIDTH,
                                        SCREEN_HEIGHT);
            if (texture == NULL){
                cout << "Could not create texture !!" << endl;

                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();

                return false;
            }
            /**/
            buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
            buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
            /**/
            memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
            memset(buffer2, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

/*          
            // to access one pixel on window 
            buffer[30000] = 0xFFFFFFFF;

            
                // we could do something  like memset
                
                for(int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++){
                    buffer[i] = 0xFFFFFFFF;
                }
*/

            return true;
    };
    
    /*----------------------------------------------------------------------------------*/

    bool Screen :: processEvents(){
        SDL_Event event;
        /**/
        while(SDL_PollEvent( &event )){
            if(event.type == SDL_QUIT)
                return false;
            
        };       
        return true;
    };
    
    /*----------------------------------------------------------------------------------*/  

    void Screen :: close(){
        delete [] buffer;
        delete [] buffer2;
        /**/
        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
    };
     
    /*----------------------------------------------------------------------------------*/ 

    void Screen :: update(){
        SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    
    /*----------------------------------------------------------------------------------*/  

    void Screen :: setPixel(int x, int y,  Uint8 red, Uint8 green, Uint8 blue){
        /**/
        if(x < 0 || x>= SCREEN_WIDTH || y<0 || y>=SCREEN_HEIGHT){
            return;
        }
        /**/
        Uint32 color = 0; 
        /* RGB */
        color += red;   //add red channel
        color <<= 8;    //bitshifting - 8bit
        color += green; //add green clannel
        color <<= 8;    //bitshifting - 8bit
        color += blue;  //add blue channel
        color <<= 8;    //bitshifting - 8bit
        color += 0xFF;  //add alpha channel
        /**/
        buffer[(y * SCREEN_WIDTH) + x] = color;
    };

    /*----------------------------------------------------------------------------------*/  

    void Screen :: clear(){
        memset(buffer, 0 , SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
        memset(buffer2, 0 , SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
    }

    /*----------------------------------------------------------------------------------*/

    void Screen :: blur(){
        Uint32* temp = buffer;
        buffer = buffer2;
        buffer2 = temp;
        /**/
        for(int y = 0; y<SCREEN_HEIGHT; y++){
            for(int x = 0; x<SCREEN_WIDTH; x++){
                /*
                    0 0 0
                    0 1 0
                    0 0 0
                */
               /**/
               int redTotal = 0;
               int greenTotal = 0;
               int blueTotal = 0;
               /**/
               for(int row = -1; row<=1; row++){
                   for(int col = -1; col<=1; col++){
                       int currentX = x + row;
                       int currentY = y + col;

                       if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT){
                            Uint32 color = buffer2[currentY*SCREEN_WIDTH + currentX];
                            /**/
                            Uint8 red = color >>24;
                            Uint8 blue = color >>16;
                            Uint8 green = color >>8;
                            /**/
                            redTotal += red;
                            greenTotal += green;
                            blueTotal += blue;
                       }
                   }
               }
               Uint8 red = redTotal/9;
               Uint8 green = greenTotal/9;
               Uint8 blue = blueTotal/9;
               /**/
               setPixel(x, y, red, green, blue);
            }
        }

    }
} /* namespace : particleScreen */


