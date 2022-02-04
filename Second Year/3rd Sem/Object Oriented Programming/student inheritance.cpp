#include <iostream>
using namespace std;

class Student{
    public:
        int id;string name;
        get_stud(){
            cout<<"Enter th id and name of the student\n";
            cin>>id>>name;
        }
        put_stud(){
            cout<<"id: "<<id<<"  name: "<<name<<"\n";
        }
};

class smarks:public Student{//get_stud() and put_stud() is same acess specifier as baase class
//class smarks:private Student{//get_stud() and put_stud() is private so main cannot access
//class smarks:protected Student{//get_stud() and put_stud() is protected so main cannot access
    public:
        int m1,m2,m3;
        get_marks(){
            cout<<"Enter the marks for 3 subjects\n";
            cin>>m1>>m2>>m3;
        }
        put_marks(){
            cout<<"marks1: "<<m1<<" ,marks2: "<<m2<<" marks3: "<<m3<<"\n";
        }
        friend int main();
};

class result:public smarks{
//class result:public smarks,public Student{
    public:
        double total,avg;
        getAvg(){
            total=m1+m2+m3;
            avg=total/3.0;
            cout<<"Total marks is "<<total<<"\n";
            cout<<"Average marks is "<<avg<<"\n";
        }
};

int main(){
    smarks sm1;
    sm1.get_stud();
    sm1.put_stud();
    sm1.get_marks();
    sm1.put_marks();
    result r1;
    r1.get_stud();
    r1.put_stud();
    r1.get_marks();
    r1.put_marks();
    r1.getAvg();
    return 0;
}
