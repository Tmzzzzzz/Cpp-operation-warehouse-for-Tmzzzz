/*
四、对第5次作业第2题动态数组类IntArray进行扩展，(如下)
使其成为存储int数据的集合类IntSet,
并增加一个成员函数insert(int)，用于向集合中增加新的数据元素。
集合的特性是其包含的数据不能重复。例如，假设集合中已含有数据元素{1，2，3}，若还要增加数据元素3，则程序应提示不能增加。
*/

#include <iostream>
using namespace std;

class IntSet{
    private:
        int* arr;
        int size;
        int count;
    public:
        IntSet(int s = 0) : size(s), count(0) {
            arr = new int[size];
        }
        ~IntSet() {
            delete[] arr;
        }
        bool insert(int value) {
            if (count >= size) {
                cerr << "集合已满，无法插入新元素" << endl;
                return false;
            }
            for (int i = 0; i < count; i++) {
                if (arr[i] == value) {
                    cerr << "元素已存在，无法插入" << endl;
                    return false;
                }
            }
            arr[count++] = value;
            return true;
        }
        int getSize() const {
            return count;
        }
        int& operator[](int index) {
            if (index < 0 || index >= count) {
                cerr << "越界访问" << endl;
                exit(1);
            }
            return arr[index];
        }
        void resize(int newSize) {
            if (newSize < count) {
                cerr << "新大小不能小于当前元素数量" << endl;
                return;
            }
            int* newArr = new int[newSize];
            for (int i = 0; i < count; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            size = newSize;
        }
};

int main()
{
	IntSet arr; //建立存储空间为0的数组对象
	arr[1]=10;   //对下标1位置的数组元素进行赋值操作；程序应提示越界访问
	arr.resize(10); //把存储空间增大为10，即可以存10个整型数值；注：存储空间的大小可增大，也可缩小
    IntSet arr2(20);  //建立存储空间为20的数组对象
	for(int i=0;i<arr2.getSize();i++)
       arr2[i]=i;
arr=arr2;  //把arr2对象的内容复制给arr对象
	for(int i=0;i<arr.getSize();i++)  //打印输出arr里的数据，即0,1,2,3…19
       cout<<arr[i]<<',';

	return 0;
}



