#ifndef TPARTICLE_H
#define TPARTICLE_H
#include "vector3d.h"

class Tparticle
{
    public:
        vector3d<double> position;
        vector3d<double> velocity;
        double mass;
        double electric_charge;
        double repulsive_charge;
        double attractive_charge;
        Tparticle();
        Tparticle(vector3d<double> Position,vector3d<double>,double,double,double,double);
        virtual ~Tparticle();
        void accelerate(vector3d<double> Force, double t)
        {
            velocity=velocity+Force/mass*t;
        }
        void motion(double t)
        {
            position=position+velocity*t;
        }

    protected:

    private:
};

#endif // TPARTICLE_H
