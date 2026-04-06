/*
三、修改“作业2”的第3题，使以下的程序输出：
Copy stack
2, 1
4, 3, 2, 1
Delete stack, size=4
Delete stack, size=2
主函数如下：
int main()
{
Stack stack;
 	stack.push(1); 
	stack.push(2);
	
    Stack stack2=stack;  //打印输出：Copy stack
	stack2.push(3);      
stack2.push(4);      

stack.print();       //打印输出：2, 1
stack2.print();     //打印输出：4, 3, 2, 1
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
    }
    Stack(const Stack& s){              //此处增加拷贝构造函数用法及输出
        capacity=s.capacity;
        top=s.top;
        arr=new int[capacity];
        for(int i=0 ; i<=top ; i++){
            arr[i]=s.arr[i];
        }
        cout<<"Copy stack"<<endl;
    }
    ~Stack(){
        delete[] arr;
        cout<<"Delete stack, size="<<top+1<<endl;   //此处增加输出
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

void Stack::print(){                //此处更改顺序，由栈顶打印到栈底
    for(int i=top;i>=0;i--){
        cout<<arr[i];
        if(i!=0){
            cout<<", ";
        }
    }
    cout<<endl;
}


int main()
{
Stack stack;
 	stack.push(1); 
	stack.push(2);
	
    Stack stack2=stack;  //打印输出：Copy stack
	stack2.push(3);      
    stack2.push(4);      

stack.print();       //打印输出：2, 1
stack2.print();     //打印输出：4, 3, 2, 1
}

