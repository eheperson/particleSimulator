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

    Swarm swarm;
    while (true){
        // Update Particles
        //Draw Particles
        const Particle* const pParticles = swarm.getParticles();
        //
        int elapsed = SDL_GetTicks();
        //
        unsigned char red = (unsigned char)( (1 + sin(elapsed*0.001))*128);
        unsigned char green = (unsigned char)( (1 + cos(elapsed*0.002))*128);
        unsigned char blue = (unsigned char)( (1 + sin(elapsed*0.003))*128);
        //
        for(int i = 0; i<Swarm::N_PARTICLES; i++){
            Particle particle = pParticles[i];
            /**/
            int x = (particle.getParticleX() + 1)*Screen::SCREEN_WIDTH/2;
            int y = (particle.getParticleY() + 1)*Screen::SCREEN_HEIGHT/2;
            /**/
            screen.setPixel(x, y, red, green, blue);
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