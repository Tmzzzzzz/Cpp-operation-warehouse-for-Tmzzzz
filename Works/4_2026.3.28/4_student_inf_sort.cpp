/*
四、	有如下学生数据，请编写程序按照总分从大到小输出学生信息，如果总分相同，则按学号从小到大排列。
学号	姓名	班级	物理	化学
20001	张三	1	    80	    85
20002	李四	2	    82	    75
20003	王五	3	    73	    68
20004	马六	3	    85	    80
20005	陈七	4	    90	    88

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Student{
    private:
        int id;
        string name;
        int Class;
        int phy;
        int chem;
        int total;
    public:
        Student(int i,string na,int cl,int ph,int ch):id(i),name(na),Class(cl),phy(ph),chem(ch){total=phy+chem;}
        int getTotal() const{
            return total;
        }
        int getId() const{
            return id;
        }
        void Print() const{
            cout<<id<<"\t"<<name<<"\t"<<Class<<"\t"<<phy<<"\t"<<chem<<endl;
        }
};

bool compare(const Student& a,const Student& b){
    if(a.getTotal()!=b.getTotal()){
        return a.getTotal()>b.getTotal();
    }
    return a.getId()<b.getId();
}

int main(){
    vector<Student> students;
    students.push_back(Student(20001,"张三",1,80,85));
    students.push_back(Student(20002,"李四",2,82,75));
    students.push_back(Student(20003,"王五",3,73,68));
    students.push_back(Student(20004,"马六",3,85,80));
    students.push_back(Student(20005,"陈七",4,90,88));
    sort(students.begin(),students.end(),compare);
    cout << "学号\t姓名\t班级\t物理\t化学" << endl;
    for(int i=0;i<students.size();i++){
        students[i].Print();
    }

}