/*
二、设计动态数组类IntArray，可以模拟整型数组的行为，并实现按下标访问、重置数组大小等功能。
所设计的类应支持深拷贝及以下主函数的运行。

主函数如下：

int main()
{
	IntArray arr; //建立存储空间为0的数组对象
	arr[1]=10;   //对下标1位置的数组元素进行赋值操作；程序应提示越界访问   
	arr.resize(10); //把存储空间增大为10，即可以存10个整型数值；注：存储空间的大小可增大，也可缩小
    IntArray arr2(20);  //建立存储空间为20的数组对象
	for(int i=0;i<arr2.size();i++)
       arr2[i]=i;
arr=arr2;  //把arr2对象的内容复制给arr对象
	for(int i=0;i<arr.size();i++)  //打印输出arr里的数据，即0,1,2,3…19
       cout<<arr[i]<<”,”;

	return 0;
}
*/

 #include <iostream>
 using namespace std;

 class IntArray {
    private:
        int index;
        int*  arr;
    public:
        IntArray():index(0),arr(new int[0]){}
        IntArray(int size){
            index = size;
            arr = new int [index] ;
        }
        IntArray(const IntArray& arr1){
            index=arr1.index;
            arr= new int [index];
            for(int i=0; i < index; i++){
                arr[i]=arr1.arr[i];
            }
        }
        IntArray & operator= (IntArray& arr2){
            index=arr2.index;
            delete[] arr; 
            arr= new int [index];
            for(int i=0; i < index; i++){
                arr[i]=arr2.arr[i];
            }
            return *this;
        }
        
        void resize(int NewSize){
            int * newArr=new int [NewSize];
            for(int i=0;i<index && i<NewSize;i++){
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            index = NewSize;
        }
        int size() const{
            return index;
        }
        int & operator[] (int i){
            if ( i>=index || i<0 ){
                cout<<"ERROR: 越界 "<<endl;
            }
            return  arr[i];
        }
        ~IntArray(){
            delete[] arr;
        }
 };


 int main()
{
	IntArray arr;       //建立存储空间为0的数组对象
	arr[1]=10;          //对下标1位置的数组元素进行赋值操作；程序应提示越界访问   
	arr.resize(10);     //把存储空间增大为10，即可以存10个整型数值；注：存储空间的大小可增大，也可缩小
    IntArray arr2(20);  //建立存储空间为20的数组对象
	for(int i=0;i<arr2.size();i++)
       arr2[i]=i;
    arr=arr2;           //把arr2对象的内容复制给arr对象
	for(int i=0;i<arr.size();i++)  //打印输出arr里的数据，即0,1,2,3…19
       cout<<arr[i]<<",";

	return 0;
}