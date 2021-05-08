#include<iostream>
#include<math.h>
#include<time.h>

#include<Screen/Screen.h> 
#include<Swarm/Swarm.h>


/**/
using namespace std;
using namespace particleScreen;
using namespace particleSimulator;
/**/
int main(int argc, char* argv[]){

    srand(time(NULL));

    Screen screen;

    if( screen.init() == false){
        cout << " Error at initializing SDL !!" << endl;
    };

    swarm swarm;
    while (true){
        // Update Particles
        //Draw Particles
        const particle* const pParticles = swarm.getParticles();
        for(int i = 0; i<swarm.getSize(); i++){
            particle particle = pParticles[i];
            /**/
            int x = (particle.getx() + 1)*Screen::SCREEN_WIDTH/2;
            int y = (particle.gety() + 1)*Screen::SCREEN_HEIGHT/2;
            /**/
            screen.setPixel(x, y, 255, 255, 255);
        }
        /*
        int elapsed = SDL_GetTicks();
        //double green = (1 + sin(elapsed*0.001))*128;
        //to animate colors uncomment : 
        unsigned char green = (unsigned char)( (1 + sin(elapsed*0.001))*128);
        for( int y = 0; y < Screen :: SCREEN_HEIGHT; y++){
            for( int x = 0; x < Screen :: SCREEN_WIDTH; x++){
                screen.setPixel(x, y, 0, green, 0);
            }
        }
        //screen.setPixel( 400, 300, 255, 255, 255);
        */

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