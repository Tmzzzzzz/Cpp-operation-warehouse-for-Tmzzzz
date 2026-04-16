/*
一、定义类A、A1和A2，其中A1由类A公有派生，A2由类A1公有派生。请按下列要求编写程序。

定义类A的构造函数，该构造函数有一个整型的参数x，
在构造函数中将x赋值给数据成员a;

定义类A1的构造函数，该构造函数有两个整型的参数x和y，
在构造函数中将x赋值给数据成员b，将y作为基类A的构造函数的参数值传入；

定义类A2的构造函数，该构造函数有3个整型的参数x, y和z，
在构造函数中将x赋值给数据成员c，将y和z分别赋值给基类A1的构造函数的参数x和y。

完成类A2的成员函数show的定义，
该函数输出类A2自身的数据成员c的值，并调用基类成员函数，输出基类数据成员a和b的值。
*/
#include <iostream>
using namespace std;

class A{
    private:
        int a;
    public:
        A(int x):a(x){}
        int Get_a(){return a;}
};

class A1 : public A {
    private:
        int b;
    public:
        A1(int x , int y):b(x),A(y){}
        int Get_b(){return b;}
};

class A2 : public A1{
    private:
        int c;
    public:
        A2(int x, int y, int z):c(x),A1(y,z){}
        void show(){
            cout<< "c:" << c << endl;
            cout<< "a:" << Get_a() << " b:" << Get_b() <<endl;
        }
    };

int main(){
    A2 a(3,6,9);
    a.show();
    return 0;
}
