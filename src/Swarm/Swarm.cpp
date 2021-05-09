/**/
/**/
#include <stdlib.h>
#include <iostream>
/**/
#include "swarm.h"
/**/
namespace particleSimulator{
    /**/
    /*----------------------------- Constructor and Deconstructor Methods Definitions */
    /**/
    swarm :: swarm(){
        lastTime = 0;
        particlesPtr = new particle[swarmSize];
    };
    /**/
    swarm :: ~swarm(){
        delete [] particlesPtr; // we need to use '[]', because mParticlePtr is an aray
    };
    /**/
    /*-------------------------------------------Set Methods Definitions */
    /**/
    void swarm :: setvxy( double speed){
        for(int i = 0; i <swarmSize; i++){
            particlesPtr[i].setvx(speed);
            particlesPtr[i].setvy(speed);
        }
    }
    /**/
    void swarm :: setvRandom(){
        for(int i = 0; i <swarmSize; i++){
            particlesPtr[i].setvxRandom();
            particlesPtr[i].setvyRandom();
        }
    }
    /**/
    /*-------------------------------------------Get Methods Definitions */
    /**/
    int swarm :: getSize(){
        return swarmSize;
    }
    /**/
    /**/
    /**/    
    /**/
    /**/
    /**/
    /*-------------------------------------------Other Methods Definitions */
    /**/
    void swarm :: movexy(bool border, int elapsed){
        /**/    
        int interval = elapsed - lastTime;
        /**/
        if(border){
            for(int i = 0; i < swarmSize; i++){
                particlesPtr[i].movexy(true, interval);
            }
        }
        else{
            for(int i = 0; i < swarmSize; i++){
                particlesPtr[i].movexy(false, interval);
            }
        }
        /**/
        lastTime = elapsed;
    }
    /**/
} /* namespace : particleSimulator*/