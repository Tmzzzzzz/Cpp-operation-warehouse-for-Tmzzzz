/*
二、email地址的格式：账户名+@+服务器域名，请编写一个类表示email地址。
*/

#include <iostream>
using namespace std;

class email{
    private:
    string account;
    string domain;
    public:
    email(){
        account="";
        domain="";
    }
    void setAccount(string a){
        account=a;
    }
    void setDomain(string d){
        domain=d;
    }
    void show(){
        cout<<account<<"@"<<domain<<endl;
    }
};