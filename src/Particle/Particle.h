#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particleSimulator{

    class Particle{
        private:
            double mX;
            double mY;

        public:
            Particle();
            virtual ~Particle();
            double getParticleX();
            double getParticleY();

    };
}  /* namespace : particleSimulator*/

#endif /* PARTICLE_H_*/