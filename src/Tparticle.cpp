#include "Tparticle.h"

Tparticle::Tparticle()
{
    position=vector3d<double>();
    velocity=vector3d<double>();
    mass=1;
    electric_charge=0;
    repulsive_charge=1;
    attractive_charge=0;
}
Tparticle::Tparticle(vector3d<double> Position, vector3d<double> Velocity, double Mass, double Electric_charge, double Repulsive_charge, double Attractive_charge)
{
    position=Position;
    velocity=Velocity;
    mass=Mass;
    electric_charge=Electric_charge;
    repulsive_charge=Repulsive_charge;
    attractive_charge=Attractive_charge;
}
Tparticle::Tparticle(vector3d<double> Position, vector3d<double> Velocity, double Mass, double Electric_charge, double Repulsive_charge, double Attractive_charge, vector3d<double> Color)
{
    position=Position;
    velocity=Velocity;
    mass=Mass;
    electric_charge=Electric_charge;
    repulsive_charge=Repulsive_charge;
    attractive_charge=Attractive_charge;
    color=Color;
}
Tparticle::~Tparticle()
{
    //dtor
}
