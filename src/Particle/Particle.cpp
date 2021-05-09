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
        calculatetheta();
        calculater();
        calculatevx();
        calculatevy();
    };
    /**/
    particle :: particle(std::string coordinate, 
                        double xtheta, double yr, 
                        double vxV, double vyphi){
        /**/
        if(coordinate == "cartesian"){
            setx(xtheta);
            sety(yr);
            setvx(vxV);
            setvy(vyphi);
            /**/
            calculatetheta();
            calculater();
            calculateV();
            calculatephi();
        }
        else if(coordinate == "polar"){
            settheta(xtheta);
            setr(yr);
            setV(vxV);
            setphi(vyphi);
            /**/
            calculatex();
            calculatey();
            calculatevx();
            calculatevy();
        }
        else{
            std :: cout << "Undefined Coordinate System !!" << std :: endl;
        }
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
    void particle :: setvx(double vx){
        particle :: vx = vx;
    };
    /**/
    void particle :: setvy(double vy){
        particle :: vy = vy;
    };
    /**/
    void particle :: setV(double V){
        particle :: V = V;
    };
    /**/
    void particle :: setphi(double phi){
        particle :: phi = phi;
    };
    /**/
    void particle :: setr(double r){
        particle :: r = r;
    };
    /**/
    void particle :: settheta(double theta){
        particle :: theta = theta;
    };
    /**/
    void particle :: setxRandom(){
        x = ((2.0 * rand())/RAND_MAX) - 1;
    }
    /**/
    void particle :: setyRandom(){
        y = ((2.0 * rand())/RAND_MAX) - 1;
    }
    /**/
    void particle :: setVRandom(){
        V = ((0.04 * rand())/RAND_MAX);
    }
    /**/
    void particle :: setphiRandom(){
         phi = ((2.0 * M_PI * rand())/RAND_MAX);
    }
    /**/
    void particle :: setvxRandom(){
        //particle :: vx = ((0.001 * rand())/RAND_MAX);
        //particle :: vx = ((2.0 * rand())/RAND_MAX) - 1;
        particle :: vx = 0.001*(((2.0 * rand())/RAND_MAX) - 1);
    }
    /**/
    void particle :: setvyRandom(){
        //particle :: vy = ((0.001 * rand())/RAND_MAX);
        //particle :: vy = ((2.0 * rand())/RAND_MAX) - 1;
        particle :: vy = 0.001*(((2.0 * rand())/RAND_MAX) - 1);
    }
    /**/
    /*-------------------------------------------Get Methods Definitions */
    /**/
    double particle :: getx(){
        return x;
    };
    /**/
    double particle::gety(){
        return y;
    };
    /**/
    double particle :: getvx(){
        return particle :: vx;
    }
    /**/
    double particle :: getvy(){
        return particle :: vy;
    }
    /**/
    double particle :: getV(){
        return particle :: V;
    }
    /**/
    double particle :: getphi(){
        return particle :: phi;
    }
    /**/
    double particle :: getr(){
        return particle :: r;
    }
    /**/
    double particle :: gettheta(){
        return particle :: theta;
    }
    /**/
    /*-------------------------------------------Calculation Methods Definitions */
    /**/
    void particle :: calculatex(){
        particle :: x = r*cos(theta);
    };
    /**/
    void particle :: calculatey(){
        particle :: y = r*sin(theta);
    };
    /**/
    void particle :: calculateV(){
        particle :: V = sqrt(vx*vx + vy*vy);
    };
    /**/
    void particle :: calculatevx(){
        particle :: vx = V*cos(phi);
    };
    /**/
    void particle :: calculatevy(){
        particle :: vy = V*sin(phi);
    };
    /**/
    void particle :: calculatetheta(){
        particle :: theta = atan(y/x);
    };
    /**/
    void particle :: calculatephi(){

    };
    /**/
    void particle :: calculater(){
        particle :: r = sqrt(x*x + y*y);
    };
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
    void particle::movex(bool border, int interval){
        if(border){
            x += getvx()*interval;
            /**/
            if(x < -1.0 ||  x > 1.0){
                vx =-getvx()*interval;
            };
        }
        else{
            x += getvx()*interval;
        };
    };
    /**/
    void particle::movey(bool border, int interval){
        if(border){
            y += getvy()*interval;
            /**/
            if(y < -1.0 ||  y > 1.0){
                vy = -getvy()*interval;
            };
        }
        else{
            y += getvy()*interval;
        };
    };
    /**/
} /* namespace : particleSimulator */