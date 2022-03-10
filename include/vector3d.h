#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <cmath>

template <class T>
class vector3d
{
    public:
        T x;
        T y;
        T z;
        vector3d();
        vector3d(T, T, T);
        T sum();
        virtual ~vector3d();
        T length();
        T scalar_mult(vector3d<T>);

    protected:

    private:
};
template <class T>
vector3d<T>::vector3d()
{
    x=0;
    y=0;
    z=0;
}

template <class T>
vector3d<T>::vector3d(T X, T Y, T Z)
{
    x=X;
    y=Y;
    z=Z;
}

template <class T>
T vector3d<T>::length()
{
    return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}

template <class T>
T vector3d<T>::sum()
{
    return fabs(x)+fabs(y)+fabs(z);
}

template <class T>
T vector3d::scalar_mult(vector3d<T> mult)
{
    return x*mult.x+y*mult.y+z*mult.z;
}
template <class T>
vector3d<T>::~vector3d()
{
    //dtor
}
template <class T>
vector3d<T> operator / (const vector3d<T>& a, const double& b)
    {
        return vector3d<T>(a.x/b,a.y/b,a.z/b);
    }
template <class T>
vector3d<T> operator * (const vector3d<T>& a, const double& b)
    {
        return vector3d<T>(a.x*b,a.y*b,a.z*b);
    }
template <class T>
vector3d<T> operator + (const vector3d<T>& a, const vector3d<T>& b)
    {
        return vector3d<T>(a.x+b.x,a.y+b.y,a.z+b.z);
    }
template <class T>
vector3d<T> operator - (const vector3d<T>& a, const vector3d<T>& b)
    {
        return vector3d<T>(a.x-b.x,a.y-b.y,a.z-b.z);
    }
#endif // VECTOR3D_H
