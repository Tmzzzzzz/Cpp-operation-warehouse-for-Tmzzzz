/*
一、先设计一个圆类Circle，具有计算圆面积的功能。
再以圆类Circle为基础，设计一个圆柱体类Cylinder，具有计算圆柱体积的功能。（以类组合的方式实现）
*/

#include <iostream>
using namespace std;

double pi = 3.14159;

class Circle{
    private:
        double r;
    public:
        Circle(): r(0) {}
        Circle(double r1): r(r1) {}
        double Get_area () const {
            return pi*r*r;
        }
};

class Cylinder{
    private:
        double h;
        Circle base;
    public:
        Cylinder (double h1,const Circle& bottom):h(h1), base(bottom) {}
        double Get_volume () const {
            return h*base.Get_area();
        }
};

int main(){
    Circle s1(10);
    cout<<s1.Get_area()<<endl;
    Cylinder v1(10,s1);
    cout<<v1.Get_volume()<<endl;
    return 0;
}