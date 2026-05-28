/*
二、编写一个动态数组类模板（即课件L10中的例10-3）。
*/
#include <iostream>

using namespace std;

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
};