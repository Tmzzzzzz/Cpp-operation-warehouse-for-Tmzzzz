/*
一、向量 (vector) 的增删改查，要求：
1.	创建一个vector<int>容器，手动添加 5 个整数（例如：10,20,30,40,50）
2.	在容器末尾添加一个新元素 60
3.	删除容器第一个元素
4.	遍历并打印所有元素
5.	统计并输出容器中元素的总个数

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {10, 20, 30, 40, 50};
    vec.push_back(60);
    vec.erase(vec.begin());
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
    cout << "总个数: " << vec.size() << endl;
    return 0;
}
