#ifndef SWARM_H_
#define SWARM_H_

#include <Particle/Particle.h>

namespace particleSimulator{

    class Swarm{
        public :
            const static int N_PARTICLES = 500;
        private:
            Particle* mParticlesPtr;

        public:
            Swarm();
            virtual ~Swarm();

            const Particle* const getParticles();

    };
}  /* namespace : particleSimulator*/

#endif /* SWARM_H_*/