#ifndef INC_3D_CURVES_CURVE_H
#define INC_3D_CURVES_CURVE_H
#include <string>

using namespace std;

struct Point3D
{
    double x,y,z;
};

struct Derivative
{
    double  x, y, z;
};

class Curve
{
public:
    Curve() = default;

    virtual Point3D GetPoint3D(double t);

    virtual Derivative GetDerivative(double t);

    virtual void PrintParams();

    virtual string GetType();
};


#endif //INC_3D_CURVES_CURVE_H
