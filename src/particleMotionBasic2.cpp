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
        int elapsed = SDL_GetTicks();
        screen.clear();
        swarm.movexy(true);
        //
        //
        unsigned char red = (unsigned char)( (1 + sin(elapsed*0.0001))*128);
        unsigned char green = (unsigned char)( (1 + cos(elapsed*0.0002))*128);
        unsigned char blue = (unsigned char)( (1 + sin(elapsed*0.0003))*128);
        //
        const particle * const pParticles = swarm.getParticles();
        //
        for(int i = 0; i<swarm.getSize(); i++){
            particle particle = pParticles[i];
            /**/

            // cout<<i<<endl;
            
            /**/
            int x = (particle.getx() + 1)*Screen::SCREEN_WIDTH/2;
            int y = (particle.gety() + 1)*Screen::SCREEN_HEIGHT/2;
            /**/
        
            screen.setPixel(x, y, red, green, blue);
        };

        
        


        //screen.setPixel( 400, 300, 255, 255, 255);
        

        //Draw the Screen
        screen.update();

        //Check For Messages/Events

        if(screen.processEvents() == false){
            break;
        };

    };
    
    screen.close();
    return 0;

}