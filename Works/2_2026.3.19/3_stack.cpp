/*
三、栈是一种先进后出的数据结构。
请编写一个实现栈功能的类，可存储int数据，可打印栈中元素，执行出栈、入栈操作。
出栈：把栈顶元素删除；
入栈：把元素加入栈种，且处于栈顶位置；
注：关于栈数据结构，可参看：https://baike.baidu.com/item/%E6%A0%88/12808149?fr=aladdin
主函数如下：
int main()
{
Stack stack;
    stack.print();  //打印栈中的所有元素，打印顺序为从栈底到栈顶；打印格式自拟
	stack.pop();   //出栈
	stack.push(1); //入栈
	stack.push(2);
	stack.print();
	stack.pop();
	stack.print();
}

*/

#include <iostream>
using namespace std;
class Stack{
    private:
    int* arr;
    int capacity;
    int top;
    public:
    void pop();
    void push(int a);
    void print();
    Stack(){
        arr=new int[100];
        capacity=100;
        top=-1;
    };
    ~Stack(){
        delete[] arr;
    }
};

void Stack::pop(){
    if(top==-1){
        return ;
    }
    top--;
}

void Stack::push(int a){
    if(top==capacity){
        capacity*=2;
        int *newArr=new int[capacity];
        for(int i=0;i<=top;i++){
            newArr[i]=arr[i];
        }
        arr=newArr;
        delete[] newArr;
    }
    arr[++top]=a;
}

void Stack::print(){
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
Stack stack;
    stack.print();  //打印栈中的所有元素，打印顺序为从栈底到栈顶；打印格式自拟
	stack.pop();   //出栈
	stack.push(1); //入栈
	stack.push(2);
	stack.print();
	stack.pop();
	stack.print();
}
