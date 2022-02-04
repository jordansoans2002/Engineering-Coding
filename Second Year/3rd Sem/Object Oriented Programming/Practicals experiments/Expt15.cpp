#include <math.h>
#include <iostream>
using namespace std;

class Distance{
    public:
        int feet,inch;

        getDistance(){
            this->inch=inch%12;
            this->feet=feet+inch/12;
        }

        void printDistance(){
            cout<<"Distance is feet and inches is "<<feet<<"'"<<inch<<"\"";
        }

        void operator+(Distance d){
            int totalInches=inch+d.inch;
            int totalFeet=feet+d.feet+totalInches/12;
            totalInches%=12;
            cout<<"Sum of distance is feet and inches is "<<totalFeet<<"'"<<totalInches<<"\"";
        }
        void operator-(Distance d){
            int totalInches=abs(inch-d.inch);
            int totalFeet=abs(feet-d.feet)+totalInches/12;
            totalInches%=12;
            cout<<"Difference of distance is feet and inches is "<<totalFeet<<"'"<<totalInches<<"\"";
        }
};


int main(){
    Distance d1;
    cout<<"enter the distance in feet and inches\n";
    cin>>d1.feet>>d1.inch;
    d1.getDistance();
    Distance d2;
    cout<<"enter the distance in feet and inches\n";
    cin>>d2.feet>>d2.inch;
    d2.getDistance();
    d1+d2;
    cout<<"\n";
    d1-d2;
}
/*
enter the distance in feet and inches
10 20
enter the distance in feet and inches
10 21
Sum of distance is feet and inches is 21'5"
Difference of distance is feet and inches is 0'1"
*/
