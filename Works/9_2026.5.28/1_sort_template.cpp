/*
一、请写有一个名为sort的函数模板，可以对一组int类型的数、或者一组float类型的数、或一组Student类型的对象进行从小到大的排序。其中，Student类型的定义如下：
struct Student{
   string name;
   int age;
};
对Student对象的排序规则是：先按姓名从小到大排序，在根据年龄从小到大排序。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
   string name;
   int age;
};

template <typename T>
void sort(T arr[] , int n){
    for(int i = 0 ; i < n - 1 ; i++ ){
        for(int j = 0 ; j < n - i - 1 ; j++ ){
            if(arr[j] > arr[j + 1]){
                swap(arr[j] , arr[j + 1]);
            }
        }
    }
}

bool operator>(const Student& s1, const Student& s2){
    if(s1.name != s2.name)
        return s1.name > s2.name;
    return s1.age > s2.age;
}