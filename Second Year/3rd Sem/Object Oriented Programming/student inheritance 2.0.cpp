#include <iostream>
using namespace std;

class Student{
    protected:
        int id/*,m1*/;string name;
        get_stud(){
            cout<<"get_stud() in Student\n";
            cout<<"Enter th id and name of the student\n";
            cin>>id>>name;
        }
        put_stud(){
            cout<<"id: "<<id<<"  name: "<<name<<"\n";
        }
};

class smarks{//get_stud() and put_stud() is same acess specifier as baase class
//class smarks:public Student{//get_stud() and put_stud() is same acess specifier as baase class
//class smarks:private Student{//get_stud() and put_stud() is private so main cannot access
//class smarks:protected Student{//get_stud() and put_stud() is protected so main cannot access
    public:
        int m1,m2,m3;
        get_stud(){
            cout<<"get_stud() in smarks\n";
        }
        get_marks(){
            cout<<"Enter the marks for 3 subjects out of 50\n";
            cin>>m1>>m2>>m3;
        }
        put_marks(){
            cout<<"marks1: "<<m1<<" ,marks2: "<<m2<<" marks3: "<<m3<<"\n";
        }

//using operator overloading
         void operator==(smarks s){
            if(m1==s.m1&&m2==s.m2&&m3==s.m3)
                cout<<"marks are same";
            else cout<<"marks are not same";
         }
         void operator+(smarks s1){
            cout<<m1+s1.m1<<" "<<m2+s1.m2<<" "<<m3+s1.m3;
         }
         void operator%(smarks){
            cout<<(m1+m2+m3)*100/150<<"%";
         }
         void operator!(){
            if(m1+m2+m3>60)
                cout<<"pass";
            else
                cout<<"fail";
         }


};

//class result:public smarks{
class result:public smarks,public Student{
    public:
        double total,avg;
        disp(){
            Student::get_stud();
            Student::put_stud();
            smarks::get_marks();
            smarks::put_marks();
        }
        getAvg(){
            total=m1+m2+m3;
            avg=total/3.0;
            cout<<"Total marks is "<<total<<"\n";
            cout<<"Average marks is "<<avg<<"\n";
        }
};

int main(){
    smarks sm1,sm2,sm3;
    /*sm1.get_stud();
    sm1.put_stud();*/
    sm1.get_marks();
    //sm2.get_marks();
    //sm3.get_marks();
    //sm1==sm2;
    //sm1+sm2;
    //sm1%sm1;
    !sm1;
    result r1,r2,r3;
    /*r1.disp();
    r1.getAvg();*/
    return 0;
}
