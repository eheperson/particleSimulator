#ifndef SWARM_H_
#define SWARM_H_

#include <Particle/Particle.h>

namespace particleSimulator{

    class Swarm{
        public :
            const static int N_PARTICLES = 1000;
        private:
            Particle* mParticlesPtr;

        public:
            Swarm();
            virtual ~Swarm();
            const Particle * const getParticles(){ return mParticlesPtr; };
            void setSpeed(double speedC); 
            void SetSpeedXY(double speedX, double speedY); /* Not Declared Yet*/
            void setSpeedRandom(); 
            /**/
            void moveXYs(bool border);
            void moveXs(bool border); /* Not Declared Yet*/
            void moveYs(bool border); /* Not Declared Yet*/
    };
}  /* namespace : particleSimulator*/

#endif /* SWARM_H_*/