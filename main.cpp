#include <iostream>
#include <vector>
#include "gl.h"
#include "gl_handler.h"
#include "Tparticle.h"
using namespace std;

vector<Tparticle> bus;
const double t=0.0001;

void draw_particles(const vector<Tparticle>* objects)
{
    for(auto& part:*objects)
    {
        glBegin(GL_POINTS);
        glColor3d(part.color.x,part.color.y,part.color.z); glVertex3d(part.position.x,part.position.y,part.position.z);
        glEnd();
    }
}
void interactions()
{
    for(auto& part:bus)
    {
        vector3d<double> force;
        for(auto& part2:bus)
        {
            vector3d<double> dist(part2.position.x-part.position.x,part2.position.y-part.position.y,part2.position.z-part.position.z);
            if(dist.length()==0)
            {
                continue;
            }
            double f_e,f_r,f_a=0;
            if(part.electric_charge*part2.electric_charge!=0)
            {
                f_e=9*fabs(part.electric_charge*part2.electric_charge)/pow(dist.length(),2)*fabs(part.electric_charge*part2.electric_charge)/(part.electric_charge*part2.electric_charge)*(-1);
            }
            if(part.repulsive_charge*part2.repulsive_charge!=0)
            {
                f_r=fabs(part.repulsive_charge*part2.repulsive_charge)/pow(dist.length(),3)*fabs(part.repulsive_charge*part2.repulsive_charge)/(part.repulsive_charge*part2.repulsive_charge);
            }
            if(part.attractive_charge*part2.attractive_charge!=0)
            {
                f_a=fabs(part.attractive_charge*part2.attractive_charge)/pow(dist.length(),2)*fabs(part.attractive_charge*part2.attractive_charge)/(part.attractive_charge*part2.attractive_charge);
            }
            force=force+vector3d<double>(f_e*dist.x/dist.sum(),f_e*dist.y/dist.sum(),f_e*dist.z/dist.sum());
            force=force-vector3d<double>(f_r*dist.x/dist.sum(),f_r*dist.y/dist.sum(),f_r*dist.z/dist.sum());
            force=force+vector3d<double>(f_a*dist.x/dist.sum(),f_a*dist.y/dist.sum(),f_a*dist.z/dist.sum());
        }
        part.accelerate(force,t);
        cout<<"F:"<<force.length()<<"\n";
        cout<<"Pos:"<<part.position.length()<<"\n";
        cout<<"v:"<<part.velocity.length()<<"\n";
    }
    for(auto& part:bus)
    {
        part.motion(t);
    }
}
void gl_init()
{
    bus.push_back(Tparticle(vector3d<double>(0,-0.1,0),vector3d<double>(),2,-1,1,0));
    bus.push_back(Tparticle(vector3d<double>(0.25,0,0),vector3d<double>(),2,-1,1,0));
    bus.push_back(Tparticle(vector3d<double>(0.25,0.2,0),vector3d<double>(),10,4,1,0));
    glEnable(GL_DEPTH_TEST);
}
bool gl_msg(MSG& msg)
{
    return 0;
}

void gl_main()
{
    interactions();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_particles(&bus);
}
