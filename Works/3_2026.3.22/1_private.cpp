/*
一、请写一个程序举例说明为什么应将数据成员的访问限定符设置为private。在源代码中用注释说明理由。
*/
#include <iostream>
using namespace std;

class Aclass{
    private:
        int data;                                       //1.对数据成员data进行封装，防止外部直接访问，保证数据安全性
    public:                                             //2.将对必要操作集中在对外的接口中，更易于维护和修改
        Aclass(int d){data = d;}                        //初始化确保数据成员data的合法性
        void setData(int d) { data = d; }               //为外部提供设置数据成员data的接口
        void getData() const { cout << data << endl; }  //为外部提供获取数据成员data的接口
};

int main() {        //通过类的成员函数进行操作而不关注数据的具体实现，修改内部实现时不影响外部调用
    Aclass obj(5);  //创建Aclass类的对象并初始化，确保这是一个合法的对象
    obj.getData();     
    obj.setData(10);    
    obj.getData();
    return 0;
}