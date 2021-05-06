/**/
/**/
#include <stdlib.h>
#include <iostream>
/**/
#include "Swarm.h"

namespace particleSimulator{

    Swarm :: Swarm(){
        mParticlesPtr = new Particle[N_PARTICLES];
        // mX = ((2.0 * rand())/RAND_MAX) - 1;
        // mY = ((2.0 * rand())/RAND_MAX) - 1;
    };

    Swarm :: ~Swarm(){
        delete [] mParticlesPtr; // we need to use '[]', because mParticlePtr is an aray

    };

    const Particle* const Swarm::getParticles(){
        return mParticlesPtr;
    };




}