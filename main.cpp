#include <iostream>
#include <vector>
#include "gl.h"
#include "gl_handler.h"
#include "Tparticle.h"
using namespace std;

vector<Tparticle> bus;
const double t=0.0001;
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
            double f_e=9*fabs(part.electric_charge*part2.electric_charge)/pow(dist.length(),2);
            double f_r=fabs(part.repulsive_charge*part2.repulsive_charge)/pow(dist.length(),3);
            force=force+vector3d<double>(f_e*dist.x/dist.sum(),f_e*dist.y/dist.sum(),f_e*dist.z/dist.sum());
            force=force-vector3d<double>(f_r*dist.x/dist.sum(),f_r*dist.y/dist.sum(),f_r*dist.z/dist.sum());
        }
        part.accelerate(force,t);
        part.motion(t);
        cout<<"F:"<<force.length()<<"\n";
        cout<<"Pos:"<<part.position.length()<<"\n";
        cout<<"v:"<<part.velocity.length()<<"\n";
    }
}
void gl_init()
{
    bus.push_back(Tparticle(vector3d<double>(0,-0.1,0),vector3d<double>(),2,-1,1));
    bus.push_back(Tparticle(vector3d<double>(0.25,0,0),vector3d<double>(),2,-1,1));
    bus.push_back(Tparticle(vector3d<double>(0.25,0.2,0),vector3d<double>(),10,4,1));
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
    glBegin(GL_POINTS);
    glColor3d(1.0,0.0,1.0); glVertex3d(bus[0].position.x,bus[0].position.y,bus[0].position.z);
    glColor3d(1.0,0.0,1.0); glVertex3d(bus[1].position.x,bus[1].position.y,bus[1].position.z);
    glColor3d(1.0,0.0,1.0); glVertex3d(bus[2].position.x,bus[2].position.y,bus[2].position.z);
    glEnd();

}
