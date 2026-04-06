/*
一、某多项式是由多个简单项构成的，可能的形式为 ax^m+bx^n+c或ax或bx^m或c等，请编写程序求多项式的值。
输入：x的值以及多项式表达式（如2x^2-6x^3）；
输出：多项式的值
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double Cal(int x,string expr){
    
    double result=0;
    int len=expr.length();

    for(int i=0;i<len;i++){
        if(expr[i]==' ')continue;

        int sym=1;  //符号处理

        if(expr[i]=='+'){
            sym=1;  // 正号
            i++;
        }else if(expr[i]=='-'){
            sym=-1;  // 负号
            i++;
        }

        double num=1; //存x的系数或常数
        double temp=1;  //存x，无x则为1

        if(i<len&&isdigit(expr[i])){
            num=0;   
            while(i<len&&isdigit(expr[i])){
                num=num*10+expr[i]-'0'; 
                i++;
            }
        }

        if(i<len&&expr[i]=='x'){
            int exp=1;
            i++;
            if(i<len&&expr[i]=='^'){
                i++;
                exp=0;
                while(i<len&&isdigit(expr[i])){
                    exp=exp*10+expr[i]-'0';
                    i++;
                }
            }else{
                exp=1;
            }
            temp*=pow(x,exp);
        }

        result+=sym*num*temp;   //res=符号*系数*x的exp次方
        i--;    //回退上一位（for循环会进入下一位），防止漏判符号
    }
    return result;
}

int main(){
    int x;
    string expr;
    cout<<"输入x"<<endl;
    cin>>x;
    cout<<"输入表达式"<<endl;
    cin>>expr;
    double result=Cal(x,expr);
    cout<<"结果是"<<result<<endl;
}