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
            /**/
            double theta;
            double r;
            /**/
            double V;
            double phi;
            double vx;
            double vy;
            /**/
            /* Calculation Methods Declerations*/
            void calculatex(); 
            void calculatey(); 
            void calculateV(); /* Not Declared Yet*/ 
            void calculatevx(); /* Not Declared Yet*/ 
            void calculatevy(); /* Not Declared Yet*/ 
            void calculater(); /* Not Declared Yet*/ 
            void calculatetheta();  /* Not Declared Yet*/
            void calculatephi(); /* Not Declared Yet*/
            /**/
        public:
            /**/
            /* Constructor and Deconstructor declerations*/
            /**/
            particle();
            /**/
            particle(std::string coordinate, 
                     double xtheta, double yr, 
                     double vxV, double vyphi);
            /**/
            virtual ~particle();
            /* Set Methods Declerations*/
            void setx(double x); 
            void sety(double y);
            void setvx(double vx); 
            void setvy( double vy);
            void setV(double V);
            void setphi(double phi); 
            void setr(double r); 
            void settheta(double theta);
            /**/
            void setxRandom();
            void setyRandom();
            void setvxRandom();
            void setvyRandom();
            void setVRandom();
            void setphiRandom();
            /**/
            /* Get Methods Declerations*/
            /**/
            double getx();
            double gety();
            double getvx(); 
            double getvy(); 
            double getV(); 
            double getphi();
            double getr(); 
            double gettheta();
            /**/
            /* Movement Methods Declerations*/
            /**/
            void movexy(bool border, int interval);
            void movex(bool border, int interval);  
            void movey(bool border, int interval);      
            /**/
    }; /* class : particle*/
}  /* namespace : particleSimulator*/

#endif /* PARTICLE_H_*/