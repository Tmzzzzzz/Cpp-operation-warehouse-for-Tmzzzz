/*
五、请设计一个类Foo，可以统计当前已生成且处于活动状态的对象个数：
 以下为程序输出:
创建第1个对象
创建第2个对象
当前对象数：2
创建第3个对象
当前对象数：2

#include <iostream>
using namespace std;

  请在此处补充代码；

void func(Foo obj)
{
	
}
 
int main()
{
	Foo obj1;
	Foo obj2;
	cout<<"当前对象数："<<Foo::getNum()<<endl; 
	func(obj1);
	cout<<"当前对象数："<<Foo::getNum()<<endl; 
	return 0;
}
*/

#include <iostream>
using namespace std;

class Foo{
    private:
        static int cnt;
    public:
        Foo(){
            cnt++;
            cout<<"创建第"<<cnt<<"个对象"<<endl;
        }
        Foo(const Foo& other) {
            cnt++;
            cout << "创建第" << cnt << "个对象" << endl;
        }
        ~Foo(){
            cnt--;
        }
        static int getNum(){
            return cnt;
        }
};

int Foo::cnt=0;

void func(Foo obj)
{

}
 
int main()
{
	Foo obj1;
	Foo obj2;
	cout<<"当前对象数："<<Foo::getNum()<<endl; 
	func(obj1);
	cout<<"当前对象数："<<Foo::getNum()<<endl; 
	return 0;
}