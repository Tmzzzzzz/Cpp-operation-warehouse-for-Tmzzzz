/*
六、在上题的基础上，重新设计Foo类，使得该类的对象最多不能超过3个。
提示：在主函数中，不能通过构造函数来创建对象，要禁止以下的代码编译通过：
      Foo obj;
      如果允许这样的代码，则无法控制生成的对象个数（因为以上的代码重复写N行，就能创建N个Foo对象）。
*/
#include <iostream>
using namespace std;

class Foo{
      private:
            static int cnt;
            static const int max=3;
            Foo(){
                  cnt++;
                  cout<<"创建第"<<cnt<<"个对象"<<endl;
            }
            Foo(const Foo& foo){
                  cnt++;
                  cout<<"创建第"<<cnt<<"个对象"<<endl;
            }
      public:
            static Foo* create(){   //使用指针进行创建
                  if(cnt<max){
                        return new Foo(); //创建新对象，调用private的构造函数
                  }else{
                        cout<<"Error: 已达上限"<<endl;
                        return nullptr;
                  }
            }

            void del(){
                  if(this!=nullptr){
                        cnt--;
                        delete this;      //清理new的内存，此题不必要
                  }
            }

            static int getNum(){
                  return cnt;
            }
};

int Foo::cnt=0;

void func(Foo* obj)     //此时调用不会产生新对象及销毁
{

}
 
int main()
{
	Foo* obj1=Foo::create();
	Foo* obj2=Foo::create();
      Foo* obj3=Foo::create();
      Foo* obj4=Foo::create();
	cout<<"当前对象数："<<Foo::getNum()<<endl; 
	func(obj1); 
	cout<<"当前对象数："<<Foo::getNum()<<endl; 
	return 0;
}