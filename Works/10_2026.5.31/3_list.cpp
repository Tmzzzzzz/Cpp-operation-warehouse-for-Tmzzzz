/*
三、	列表 (list) 的高效插入与排序，要求：
1.	创建list<double>容器，存入随机浮点数：3.14, 1.59, 2.65, 0.78
2.	在容器中间位置（第 2 个元素后）插入新元素 5.20
3.	对容器进行升序排序
4.	遍历打印结果

*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<double> lst = {3.14, 1.59, 2.65, 0.78};
    auto it = next(lst.begin(), 2);
    lst.insert(it, 5.20);
    lst.sort();
    for (double n : lst) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
