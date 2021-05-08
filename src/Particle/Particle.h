#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particleSimulator{

    class Particle{
        private:
            double mX;
            double mY;
            //
            double xSpeed;
            double ySpeed;


        public:
            Particle();
            virtual ~Particle();
            /**/
            double getParticleX();
            void setParticleX(double xPoint); /* Not Declared Yet*/
            void setParticleXrandom();
            /**/
            double getParticleY();
            void setParticleY(double yPoint); /* Not Declared Yet*/
            void setParticleYrandom();
            /**/
            double getXspeed(); 
            void setXspeed(double xSpeed);  
            void setXspeedRandom();
            /**/
            double getYspeed(); 
            void setYspeed( double ySpeed); 
            void setYspeedRandom(); 
            /**/
            void moveXYp(bool border);
            void moveXp(bool border);  
            void moveYp(bool border);      

    };
}  /* namespace : particleSimulator*/

#endif /* PARTICLE_H_*/