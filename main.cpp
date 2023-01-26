#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include "Curve.h"
#include "Circle.h"
#include "Elips.h"
#include "Helixe.h"

using namespace std;

Curve *CreateRandomCurve();

int main()
{
    vector<Curve*> curves_3D;
    vector<Circle*> circles;
    int vector_size;
    cout<<"Enter vector size, //size > 0//"<<endl;
    cin>>vector_size;

    while (vector_size <= 0)
    {
        cout<<"Wrong size, enter number > 0!"<<endl;
        cin>>vector_size;
    }

    for (int i = 0; i < vector_size; i++)
    {
        Curve* new_curve = CreateRandomCurve();
        curves_3D.push_back(new_curve);
    }

    Point3D tmp_point{};
    Derivative tmp_derivative{};
    Circle tmp_circle(1);
    double t = M_PI_4;

    for (auto & curve : curves_3D)
    {
        tmp_point = curve->GetPoint3D(t);
        tmp_derivative = curve->GetDerivative(t);
        cout << endl << curve->GetType() << ":\nPoint 3D in PI/4 = {" << tmp_point.x << ", " << tmp_point.y << ", " << tmp_point.z << "}\n"
             << "Derivative 3D in PI/4 = {" << tmp_derivative.x << ", " << tmp_derivative.y << ", " << tmp_derivative.z << "}" << endl;

        if (curve->GetType() == tmp_circle.GetType())
            circles.push_back((Circle *)curve);
    }

    for (auto & circle : circles)
        circle->PrintParams();

    cout<<"Sorting..."<<endl;

    sort(circles.begin(), circles.end(), [](auto& low_circle, auto& high_circle)
    {
        return low_circle->GetRadius() < high_circle->GetRadius();
    });

    for (auto & circle : circles)
        circle->PrintParams();

    double sum = 0;

    //Parallel computations using openMP
    //I can't test it on my PC, but it should work correct
    /*
     * #pragma omp parallel
     * {
     *      #pragma omp for
     *      for (auto & circle : circles)
     *          sum += circle.GetRadius();
     * }
     */

    for (auto & circle : circles)
        sum += circle->GetRadius();

    cout<<"Sum is: "<<sum<<endl;
}

Curve *CreateRandomCurve()
{
    Curve* curve_to_return = nullptr;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist_type(1,3);
    uniform_real_distribution<double> dist_param(0,100000);

    int curve_type = dist_type(gen);

    switch (curve_type)
    {
        case 1:
        {
            double radius = dist_param(gen);

            while (radius == 0)
                radius = dist_param(gen);

            curve_to_return = new Circle(radius);
            break;
        }
        case 2:
        {
            double radius_x = dist_param(gen);
            double radius_y = dist_param(gen);

            while (radius_x == 0)
                radius_x = dist_param(gen);
            while (radius_y == 0)
                radius_y = dist_param(gen);

            curve_to_return = new Elips(radius_x,radius_y);
            break;
        }
        case 3:
        {
            double radius_x = dist_param(gen);
            double step = dist_param(gen);

            while (radius_x == 0)
                radius_x = dist_param(gen);
            while (step == 0)
                step = dist_param(gen);

            curve_to_return = new Helixe(radius_x,step);
            break;
        }
    }
    return curve_to_return;
}
