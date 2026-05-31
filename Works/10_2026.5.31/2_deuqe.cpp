/*
二、双端队列 (deque) 的双向操作，要求：
1.	创建deque<string>容器
2.	在尾部依次插入："苹果"、"香蕉"、"橙子"
3.	在头部插入："西瓜"
4.	删除尾部最后一个元素
5.	分别用下标访问和迭代器两种方式打印所有元素
6.	清空容器并验证是否为空

*/

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<string> dq;
    dq.push_back("苹果");
    dq.push_back("香蕉");
    dq.push_back("橙子");
    dq.push_front("西瓜");
    dq.pop_back();

    // 用下标访问打印所有元素
    for (size_t i = 0; i < dq.size(); ++i) {
        cout << dq[i] << " ";
    }
    cout << endl;

    // 用迭代器打印所有元素
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 清空容器并验证是否为空
    dq.clear();
    if (dq.empty()) {
        cout << "容器为空" << endl;
    }

    return 0;
}
