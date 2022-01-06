/**/
/**/
#include <stdlib.h>
#include <iostream>
#include<string>
#include<math.h>
/**/
#include "Particle.h"
/**/

/**/
namespace particleSimulator{
    /**/
    /*----------------------------- Constructor and Deconstructor Methods Definitions */
    /**/
    particle :: particle(){
        setx(0);
        sety(0);
        setVRandom();
        setphiRandom();
        /**/
        calculatevx();
        calculatevy();
    };
    /**/
    particle :: ~particle(){
        //
        //
    };
    /**/
    /*-------------------------------------------Set Methods Definitions */
    /**/
    void particle :: setx(double x){
        particle :: x = x;
    };
    /**/
    void particle :: sety(double y){
        particle :: y = y;
    };
    /**/
    void particle :: setphi(double phi){
        particle :: phi = phi;
    };
    /**/
    void particle :: setVRandom(){
        V = ((0.04 * rand())/RAND_MAX);
    }
    /**/
    void particle :: setphiRandom(){
         phi = ((2.0 * M_PI * rand())/RAND_MAX);
    }
    /**/
        void particle :: setvx(double vx){
        particle :: vx = vx;
    };
    /**/
    void particle :: setvy(double vy){
        particle :: vy = vy;
    };
    /**/
    /*-------------------------------------------Get Methods Definitions */
    /**/
    double particle :: getvx(){
        return particle :: vx;
    }
    /**/
    double particle :: getvy(){
        return particle :: vy;
    }
    /**/
    double particle :: getx(){
        return x;
    };
    /**/
    double particle::gety(){
        return y;
    };
    /*-------------------------------------------Calculation Methods Definitions */
    void particle :: calculatevx(){
        particle :: vx = V*cos(phi);
    };
    /**/
    void particle :: calculatevy(){
        particle :: vy = V*sin(phi);
    };
    /**/
    /*-------------------------------------------Movement Methods Definitions */
    /**/
    void particle::movexy(bool border, int interval){
        setphi(phi += interval*0.0003);
        calculatevx();
        calculatevy();
        if(border){
            x += getvx()*interval;
            y += getvy()*interval;
            /**/
            if(x < -1.0 ||  x > 1.0){
                vx = -getvx();
            };
            /**/
            if(y < -1.0 ||  y > 1.0){
                vy = -getvy();
            };
            /**/
            // if(x < -1 || x>1 || y<-1 || y> 1){
            //     setx(0);
            //     sety(0);
            //     setVRandom();
            //     setphiRandom();
            //     V*=V;
            // }
            // if(rand()< RAND_MAX/100){
            //     setx(0);
            //     sety(0);
            //     setVRandom();
            //     setphiRandom();
            //     V*=V;
            // }
        }
        else{
            x += getvx()*interval;
            y += getvy()*interval;
            /**/
            if(x < -1 || x>1 || y<-1 || y> 1){
                setx(0);
                sety(0);
                setVRandom();
                setphiRandom();
                V*=V;
            }
            /**/
            if(rand()< RAND_MAX/100){
                setx(0);
                sety(0);
                setVRandom();
                setphiRandom();
                V*=V;
            }
        };
    };
    /**/
} /* namespace : particleSimulator */