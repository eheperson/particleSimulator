/**/
/**/
#include <stdlib.h>
#include <iostream>
/**/
#include "Particle.h"

namespace particleSimulator{

    Particle :: Particle(){
        mX = ((2.0 * rand())/RAND_MAX) - 1;
        mY = ((2.0 * rand())/RAND_MAX) - 1;
    };

    Particle :: ~Particle(){


    };

    double Particle::getParticleX(){
        return Particle::mX;
    };

    double Particle::getParticleY(){
        return Particle::mY;
    };

}