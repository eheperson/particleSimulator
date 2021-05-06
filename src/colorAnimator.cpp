#include<iostream>
#include<math.h>
#include<Screen/Screen.h>


/**/
using namespace std;
using namespace particleScreen;
/**/
int main(int argc, char* argv[]){


    Screen screen;

    if( screen.init() == false){
        cout << " Error at initializing SDL !!" << endl;
    };

    
    while (true){
        // Update Particles

        //Draw Particles
        int elapsed = SDL_GetTicks();
        //double green = (1 + sin(elapsed*0.001))*128;
        //to animate colors : 
        unsigned char red = (unsigned char)( (1 + sin(elapsed*0.0001))*128);
        unsigned char green = (unsigned char)( (1 + sin(elapsed*0.0002))*128);
        unsigned char blue = (unsigned char)( (1 + sin(elapsed*0.0003))*128);
        for( int y = 0; y < Screen :: SCREEN_HEIGHT; y++){
            for( int x = 0; x < Screen :: SCREEN_WIDTH; x++){
                screen.setPixel(x, y, red, green, blue);
            }
        }
        //screen.setPixel( 400, 300, 255, 255, 255);

        //Draw the Screen
        screen.update();

        //Check For Messages/Events

        if(screen.processEvents() == false){
            break;
        };

    };
    
    screen.close();
    cout<<"ehe"<<endl;

    return 0;

}