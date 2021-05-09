#ifndef SWARM_H_
#define SWARM_H_

#include <Particle/Particle.h>

namespace particleSimulator{

    class swarm{
        public :
            static int const swarmSize=5000;
            int lastTime;
            /**/
        private:
            particle* particlesPtr;
            /**/
        public:
            /**/
            /* Constructor and Deconstructor declerations*/
            /**/
            swarm();
            virtual ~swarm();
            /**/
            /* Set Methods Declerations*/
            /**/
            void setSize(int s);
            void setvxy(double v); 
            void setvx(double vx); /* Not Declared Yet*/
            void setvy(double vy); /* Not Declared Yet*/
            void setvRandom(); 
            /**/
            /* Get Methods Declerations*/
            /**/
            int getSize();
            const particle * const getParticles(){ return particlesPtr; };
            /**/
            /* Other Methods Declerations*/
            /**/
            void movexy(bool border, int elapsed);
            void movex(bool border); /* Not Declared Yet*/
            void movey(bool border); /* Not Declared Yet*/
            /**/
    }; /* class : swarm*/
    /**/
}; /* namespace : particleSimulator*/
/**/
#endif /* SWARM_H_*/