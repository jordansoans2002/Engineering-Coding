#include <iostream>
using namespace std;

class Student{
    public:
    int id;string name;
    getStud(){
        cout<<"enter the student name and id\n";
        cin>>name>>id;
    }
    putStud(){
        cout<<"name is "<<name<<" and id is "<<id<<"\n";
    }
};

class marks:public virtual Student{
    public:
    int m1,m2,m3;
    getMarks(){
        cout<<"enter the marks out of 10\n";
        cin>>m1>>m2>>m3;
    }
};

class sports:public virtual Student{
    public:
    int noOfSports=0;
    getSportNumber(){
        cout<<"enter the no of sports ";
        cin>>noOfSports;
    }
    getSports(){
        string sport[noOfSports];
        cout<<"Enter names of "<<noOfSports<<" taken\n";
        for(int i=0;i<noOfSports;i++)
            cin>>sport[i];
    }
};

class result:public sports,public marks{
    public:
    int totalMarks;double percentage,adjPercentage;
    disp(){
        totalMarks=m1+m2+m3;
        percentage=(totalMarks*100)/30;
        adjPercentage=percentage+noOfSports*0.5;
        cout<<"total marks are "<<totalMarks<<"\n";
        cout<<"percentage is "<<percentage<<"\n";
        cout<<"percentage with sports marks is "<<adjPercentage<<"\n";
    }
};

int main(){
    result r1;
    //r1.getStud();
    //r1.sports::getStud();
    r1.getStud();//using virtual the system will choose a path so scope resolution is not needed
    r1.getMarks();
    r1.getSportNumber();
    r1.getSports();
    r1.marks::putStud();
    //r1.sports::putStud();
    r1.disp();
}
