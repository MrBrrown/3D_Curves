#ifndef INC_3D_CURVES_CIRCLE_H
#define INC_3D_CURVES_CIRCLE_H
#include "Curve.h"

class Circle : public Curve
{
private:
    double radius;
public:
    Circle(double  radius);

    double GetRadius();

    Point3D GetPoint3D(double t) override;

    Derivative GetDerivative(double t) override;

    void PrintParams() override;

    string GetType() override;
};


#endif
