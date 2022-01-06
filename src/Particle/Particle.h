#ifndef PARTICLE_H_
#define PARTICLE_H_
/**/
#include<string>
/**/
namespace particleSimulator{
    /**/
    class particle{
        private:
            double x;
            double y;
            double V;
            double phi;
            double vx;
            double vy;
            /* Calculation Methods Declerations*/
            void calculatevx();
            void calculatevy(); 
        public:
            particle();
            virtual ~particle();
            /* Set Methods Declerations*/
            void setx(double x); 
            void sety(double y);
            void setphi(double phi); 
            void setVRandom();
            void setphiRandom();
            void setvx(double vx);
            void setvy(double vy);
            /* Get Methods Declerations*/
            double getvx(); 
            double getvy(); 
            double getx();
            double gety();
            /* Movement Methods Declerations*/
            void movexy(bool border, int interval);
    }; /* class : particle*/
}  /* namespace : particleSimulator*/

#endif /* PARTICLE_H_*/