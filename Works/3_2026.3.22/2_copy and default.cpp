/*
二、请补充完整程序，使程序的输出为：
The default constructor has been called: 1
The copy constructor has been called: 2
The copy constructor has been called: 3
 */

#include <iostream>
using namespace std;
class Foo{
    private:
        static int cnt;     //静态变量记录调用次数
    public:
        Foo(){
            cnt++;
            cout << "The default constructor has been called: " << cnt << endl;
        }
        Foo(const Foo& obj){
            cnt++;
            cout << "The copy constructor has been called: " << cnt << endl;
        }
};

int Foo::cnt=0;

Foo method(Foo obj)     //obj作为值传入函数时调用一次拷贝构造函数
{
 	return obj;         //obj返回时调用一次拷贝构造函数
 }
 
 int main()
 {
 	Foo obj;        //初始化一个Foo类的对象obj
	method(obj);    //通过method函数调用obj
 }

