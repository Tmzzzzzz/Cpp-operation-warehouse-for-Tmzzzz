/*
三· 请设计一个学生类Student，可以统计所有学生的平均成绩
以下程序输出：
平均成绩为：75
 
#include <iostream>
using namespace std;

  请在此处补充代码；

int main()
{
	Student s1(90);
	Student s2(80);
	Student s3(70);
	Student s4(60);
	cout<<"平均成绩为："<<Student::getAvgScore()<<endl;
	return 0;
}
*/

#include <iostream>
using namespace std;

class Student{
    private:
        int score;
        static int cnt;
        static double total;
    public:
        Student(int sco){
            score=sco;
            total+=score;
            cnt++;
        }
        static double getAvgScore(){
            if(cnt==0) return 0;
            double avg=1.0*total/cnt;
            return avg;
        }
};

int Student::cnt=0;
double Student::total=0;

int main()
{
	Student s1(90);
	Student s2(80);
	Student s3(70);
	Student s4(60);
	cout<<"平均成绩为："<<Student::getAvgScore()<<endl;
	return 0;
}