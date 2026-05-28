/*
四、改造第二题所实现的动态数组类模板，增加一个构造函数，参数为表示文件路径的字符串。
该构造函数将从参数所指示的文件中读取数据以初始化数组。
在构造函数中应具有异常处理机制，
实现：当对参数所指文件读取失败时，则从默认文件（c:\data.txt）中读取数据。
注：文件格式自拟。
*/
#include <iostream>
#include <fstream>
#include <sstream>

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
    Array(const string& filename):size(50){     //本题新增构造函数
        alist = new T[size];
        ifstream file(filename);
        if (! file.is_open() ){                 //指定文件打开失败
            cerr << "Failed to open file: " << filename << endl;
            file.close();
            file.open("c:\\data.txt");          //尝试打开默认文件
            if(!file.is_open()){                //默认文件打开失败
                cerr << "Failed to open default file: c:\\data.txt" << endl;
                file.close();
                return;
            }
        }
        for (int i = 0; i < size && !file.eof(); i++) {
            file >> alist[i];                   //读入文件
        }
        file.close();
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