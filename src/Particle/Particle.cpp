/**/
/**/
#include <stdlib.h>
#include <iostream>
/**/
#include "Particle.h"

namespace particleSimulator{

    Particle :: Particle(){
        setParticleXrandom();
        setParticleYrandom();
        /**/
        setXspeedRandom();
        setYspeedRandom();
    };

    /*----------------------------------------------------------------------------------*/  

    Particle :: ~Particle(){
    };

    /*----------------------------------------------------------------------------------*/  

    double Particle :: getParticleX(){
        return mX;
    };

    /*----------------------------------------------------------------------------------*/  

    void Particle :: setParticleXrandom(){
        mX = ((2.0 * rand())/RAND_MAX) - 1;
    }

    /*----------------------------------------------------------------------------------*/  

    double Particle::getParticleY(){
        return mY;
    };

    /*----------------------------------------------------------------------------------*/  

    void Particle :: setParticleYrandom(){
        mY = ((2.0 * rand())/RAND_MAX) - 1;
    }

    /*----------------------------------------------------------------------------------*/  
    
    void Particle :: setXspeed(double xSpeed){
        Particle :: xSpeed = xSpeed;
    }

    /*----------------------------------------------------------------------------------*/  
    
    void Particle :: setXspeedRandom(){
        //Particle :: xSpeed = ((0.001 * rand())/RAND_MAX);
        //Particle :: xSpeed = ((2.0 * rand())/RAND_MAX) - 1;
        Particle :: xSpeed = 0.001*(((2.0 * rand())/RAND_MAX) - 1);
    }

    /*----------------------------------------------------------------------------------*/  
    
    void Particle :: setYspeedRandom(){
        //Particle :: ySpeed = ((0.001 * rand())/RAND_MAX);
        //Particle :: ySpeed = ((2.0 * rand())/RAND_MAX) - 1;
        Particle :: ySpeed = 0.001*(((2.0 * rand())/RAND_MAX) - 1);

    }
    /*----------------------------------------------------------------------------------*/  
    
    double Particle :: getXspeed(){
        return Particle :: xSpeed;
    }

    /*----------------------------------------------------------------------------------*/  
    
    void Particle :: setYspeed(double ySpeed){
        Particle :: ySpeed = ySpeed;
    }

    /*----------------------------------------------------------------------------------*/  
    
    double Particle :: getYspeed(){
        return Particle :: ySpeed;
    }

    /*----------------------------------------------------------------------------------*/  

    void Particle::moveXYp(bool border = true){
        if(border){
            mX += getXspeed();
            mY += getYspeed();
            /**/
            if(mX < -1.0 ||  mX > 1.0){
                xSpeed = -xSpeed;
            };
            /**/
            if(mY < -1.0 ||  mY > 1.0){
                ySpeed = -ySpeed;
            };
        }
        else{
            mX += getXspeed();
            mY += getYspeed();
        };
    };

    /*----------------------------------------------------------------------------------*/  

    void Particle::moveXp(bool border = true){
        if(border){
            mX += getXspeed();
            /**/
            if(mX < -1.0 ||  mX > 1.0){
                xSpeed = -xSpeed;
            };
        }
        else{
            mX += getXspeed();
        };
    };

    /*----------------------------------------------------------------------------------*/  

    void Particle::moveYp(bool border = true){
        if(border){
            mY += getYspeed();
            /**/
            if(mY < -1.0 ||  mY > 1.0){
                ySpeed = -ySpeed;
            };
        }
        else{
            mY += getYspeed();
        };
    };

    /*----------------------------------------------------------------------------------*/  


} /* namespace : particleSimulator */