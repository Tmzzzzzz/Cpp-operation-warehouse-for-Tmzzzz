/*
二、先设计一个圆类Circle，具有计算圆面积的功能。
再以圆类Circle为基础，设计一个圆环类Ring，具有计算圆环面积的功能。
*/

#include <iostream>
using namespace std;

class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const {
        return 3.14159 * radius * radius;
    }

};

class Ring {
public:
    Ring(double innerRadius, double outerRadius)
        : innerCircle(innerRadius), outerCircle(outerRadius) {}
    double area() const {
        return outerCircle.area() - innerCircle.area();
    }
private:
    Circle innerCircle;
    Circle outerCircle;
};