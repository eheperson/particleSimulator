/**/
/**/
#include <stdlib.h>
#include <iostream>
/**/
#include "Swarm.h"

namespace particleSimulator{
      
    Swarm :: Swarm(){
        mParticlesPtr = new Particle[N_PARTICLES];
    };
      
    /*----------------------------------------------------------------------------------*/
    
    Swarm :: ~Swarm(){
        delete [] mParticlesPtr; // we need to use '[]', because mParticlePtr is an aray
    };

    /*----------------------------------------------------------------------------------*/  
    
    // const Particle * const Swarm::getParticles(){};

    /*----------------------------------------------------------------------------------*/  
    
    void Swarm :: setSpeed( double speed){
        for(int i = 0; i <N_PARTICLES; i++){
            mParticlesPtr[i].setXspeed(speed);
            mParticlesPtr[i].setYspeed(speed);
        }
    }

    /*----------------------------------------------------------------------------------*/  
    
    void Swarm :: setSpeedRandom(){
        for(int i = 0; i <N_PARTICLES; i++){
            mParticlesPtr[i].setXspeedRandom();
            mParticlesPtr[i].setYspeedRandom();
        }
    }
       
    /*----------------------------------------------------------------------------------*/  

    void Swarm :: moveXYs(bool border = true){
        if(border){
            for(int i = 0; i < N_PARTICLES; i++){
                mParticlesPtr[i].moveXYp(true);
            }
        }
        else{
            for(int i = 0; i < N_PARTICLES; i++){
                mParticlesPtr[i].moveXYp(false);
            }
        }

    }

} /* namespace : particleSimulator*/