/*
三、改造上题，使之成为存储正方形对象的数组类SquareArray，并可按正方形边长从小到大的顺序对正方形对象进行排序。
所设计的正方形类Square、数组类SquareArray应支持深拷贝及以下主函数的运行。

主函数如下：

int main()
{
Square s1(4);
    Square s2(6);
SquareArray arr(2); //建立存储空间为2的数组对象
	arr[0]=s2;   
    arr[1]=s1;  
	arr.sort(); //按正方形边长从小到大的顺序对数组元素进行排序
    for(int i=0;i<arr.size();i++)  //打印输出arr里的各个正方形对象的边长，即4,6
       arr[i].print();

	return 0;
}
*/

#include <iostream>
using namespace std;
class Square{
    private:
        double side;
    public:
        Square():side(0) {}
        Square(double size):side(size) {}
        double getSide(){
            return side;
        }
        Square & operator= (const Square& other){
            side = other.side;
            return *this;
        }
        void print(){
            cout<<side<<",";
        }
};
 class SquareArray {
    private:
        int index;
        Square*  arr;
    public:
        SquareArray():index(0),arr(new Square[0]){}

        SquareArray(int size){
            index = size;
            arr = new Square[index] ;
        }

        SquareArray(const SquareArray& arr1){
            index=arr1.index;
            arr= new Square[index];
            for(int i=0; i < index; i++){
                arr[i]=arr1.arr[i];
            }
        }

        int size() const{
            return index;
        }

        void sort() {
        for (int i = 0; i < index - 1; i++) {
            for (int j = 0; j < index - i - 1; j++) {
                if (arr[j].getSide() > arr[j + 1].getSide()) {
                    Square temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
        SquareArray & operator= (const SquareArray& arr2){
            index=arr2.index;
            delete[] arr; 
            arr= new Square[index];
            for(int i=0; i < index; i++){
                arr[i]=arr2.arr[i];
            }
            return *this;
        }
        Square & operator[] (int i){
            if ( i>=index || i<0 ){
                cout<<"ERROR: 越界 "<<endl;
            }
            return  arr[i];
        }

        ~SquareArray(){
            delete[] arr;
        }
 };

int main()
{
    Square s1(4);
    Square s2(6);
    SquareArray arr(2); //建立存储空间为2的数组对象
	arr[0]=s2;   
    arr[1]=s1;  
	arr.sort(); //按正方形边长从小到大的顺序对数组元素进行排序
    for(int i=0;i<arr.size();i++)  //打印输出arr里的各个正方形对象的边长，即4,6
       arr[i].print();
	return 0;
}