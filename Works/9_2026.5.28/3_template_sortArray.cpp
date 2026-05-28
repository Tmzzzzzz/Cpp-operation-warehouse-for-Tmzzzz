/*
三、综合以上两题，使动态数组类模板支持对数组元素按从小到大的顺序排序。
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Student{
   string name;
   int age;
};

template <typename T>
class Array{
private:
    T* alist;
    int size;
public:
    Array(int s = 50) : size(s) {
        alist = new T[size];
    }
    Array(const Array& other){
        size = other.size;
        alist = new T[size];
        for(int i = 0; i < size; i++){
            alist[i] = other.alist[i];
        }
    }
    ~Array(){
        delete[] alist;
    }
    Array& operator=(const Array& other){
        if(this != &other){
            delete[] alist;
            size = other.size;
            alist = new T[size];
            for(int i = 0; i < size; i++){
                alist[i] = other.alist[i];
            }
        }
        return *this;
    }
    T& operator[](int index){
        return alist[index];
    }
    operator T*() const {
        return alist;
    }
    int getSize() const {
        return size;
    }
    void resize(int newsize){
        if (newsize < 0) {
            cerr << "Invalid array size." << endl;
            return;
        }
        
        if (newsize == size) {
            return;
        }
        
        T* newlist = new T[newsize];
        int copySize = (newsize < size) ? newsize : size;
        for (int i = 0; i < copySize; i++) {
            newlist[i] = alist[i];
        }
        
        delete[] alist;
        alist = newlist;
        size = newsize;
    }
    void sort(){        //修改第一题的全局函数模板为成员函数模板
        for(int i = 0; i < size - 1; i++){
            for(int j = 0; j < size - i - 1; j++){
                if(alist[j] > alist[j + 1]){
                    swap(alist[j], alist[j + 1]);
                }
            }
        }
    }
};

bool operator>(const Student& s1, const Student& s2){
    if(s1.name != s2.name)
        return s1.name > s2.name;
    return s1.age > s2.age;
}