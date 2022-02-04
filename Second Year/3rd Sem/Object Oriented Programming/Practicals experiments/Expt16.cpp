#include <iostream>
using namespace std;

class StudMarks;
class Student;

class StudMarks{
    private:
        int marks;
    public:
        void getMarks(){
            cout<<"Enter the marks ";
            cin>>marks;
        }
    friend void printInfo(Student,StudMarks);
};

class Student{
    private:
        static int s_id;
        int id,p_income;
        string name;
    public:
        Student(){
            id=s_id++;
        }

        void getInfo(){
            cout<<"enter the student's name and income\n";
            cin>>name>>p_income;
            //cout<<s.name<<sm.marks<<s.p_income;
        }
    friend void printInfo(Student,StudMarks);
};

int Student::s_id=1;

void printInfo(Student s,StudMarks sm){
    cout<<"Id:"<<s.id<<" name:"<<s.name<<" marks: "<<sm.marks;
}

int  main(){
    Student s1;
    StudMarks sm;
    s1.getInfo();
    sm.getMarks();
    printInfo(s1,sm);
    cout<<"\n";
}
/*
enter the student's name and income
A 1000
Enter the marks 50
Id:1 name:A marks: 50
*/
