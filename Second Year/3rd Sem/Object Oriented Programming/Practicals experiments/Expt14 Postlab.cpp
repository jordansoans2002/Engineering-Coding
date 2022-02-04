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
};
sum(Distance d1,Distance d2){
    int totalInches=d1.inch+d2.inch;
    int totalFeet=d1.feet+d2.feet+totalInches/12;
    totalInches%=12;
    cout<<"Sum of distance is feet and inches is "<<totalFeet<<"'"<<totalInches<<"\"";
}

difference(Distance d1,Distance d2){
    int totalInches=abs(d1.inch-d2.inch);
    int totalFeet=abs(d1.feet-d2.feet)+totalInches/12;
    totalInches%=12;
    cout<<"Difference of distance is feet and inches is "<<totalFeet<<"'"<<totalInches<<"\"";
}

int main(){
    Distance d1;
    cout<<"enter the distance in feet and inches\n";
    cin>>d1.feet>>d1.inch;
    d1.getDistance();
    Distance d2;
    cout<<"enter the distance in feet and inches\n";
    cin>>d2.feet>>d2.inch;
    d2.getDistance();
    sum(d1,d2);
    cout<<"\n";
    difference(d1,d2);

}
