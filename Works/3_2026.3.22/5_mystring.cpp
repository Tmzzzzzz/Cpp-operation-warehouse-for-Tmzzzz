/*
五、	定义一个字符串类MyString，实现求字符串长度、取子串、查找子串、串接、打印字符串等操作，并支持以下程序的运行。

主函数如下：
int main()
{
MyString str;  //初始化为空字符串
    MyString str2(“abc”);  //初始化为字符串“abc”
	cout<<str2.length()<<endl; //打印输出：3
    cout<<str2.subString(1,2)<<endl; //从位置1开始，连续取2个字符，打印输出：bc
	cout<<str2.indexOf(“bc”)<<endl; //找到待查找子串”bc”在原字符串中第一次出现的位置，打印输出：1
    cout<<str2.indexOf(“bcd”)<<endl; //查找不到子串，打印输出：-1
str.concatenate(str2); //将str2串接到str中
str.print(); //打印输出:abc
MyString str3(str);
str3.print(); //打印输出:abc
}
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class MyString{
    private:
    char* str;
    int len;
    public:
    MyString(){
        str=new char[1];
        len=0;
        str[0]='\0';
    }
    MyString(const char* f){
        len=strlen(f);
        str=new char[len + 1];
        strcpy(str,f);
    }
    MyString(const MyString& s){
        len=s.len;
        str=new char[s.len+1];
        strcpy(str,s.str);
    }
    ~MyString(){
        delete[] str;
    }
    int length(){
        len=strlen(str);
        return len;
    }

    string subString(int start,int count){
        if(start<0 || start>len || count<=0){
            return "";
        }
        if(start + count > len){
            count = len - start;
        }
        char* temp = new char[count + 1];
        for(int i=0;i<count;i++){
            temp[i]=str[start + i];
        }
        temp[count]='\0';
        string res=temp;
        delete[] temp;
        return res;
    }

    int indexOf(const char* sub){
        int sublen=strlen(sub);
        if(sublen>len)return -1;
        for(int i=0;i<len;i++){
            bool found=1;
            for(int j=0;j<sublen;j++){
                if(str[i+j]!=sub[j]){
                    found=false;
                }
            }
            if(found){
                return i;
            }
        }
        return -1;
    }

    void concatenate(const MyString& str2){
        int newlen=len+str2.len;
        char* newstr=new char[newlen+1];
        strcpy(newstr,str);
        strcat(newstr,str2.str);
        delete[] str;
        str=newstr;
        len=newlen;
    }

    void print(){
        cout<<str<<endl;
    }

};

int main()
{
MyString str;  //初始化为空字符串
    MyString str2("abc");  //初始化为字符串“abc”
	cout<<str2.length()<<endl; //打印输出：3
    cout<<str2.subString(1,2)<<endl; //从位置1开始，连续取2个字符，打印输出：bc
	cout<<str2.indexOf("bc")<<endl; //找到待查找子串”bc”在原字符串中第一次出现的位置，打印输出：1
    cout<<str2.indexOf("bcd")<<endl; //查找不到子串，打印输出：-1
str.concatenate(str2); //将str2串接到str中
str.print(); //打印输出:abc
MyString str3(str);
str3.print(); //打印输出:abc
return 0;
}