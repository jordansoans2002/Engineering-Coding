#include <iostream>
using namespace std;

class rect{
    private:
        int length,breadth;
    public:
        int area;
        void getDimensions(){
            cout<<"Enter the length and breadth ";
            cin>>length>>breadth;
        }

        friend int calc_area(rect);
};

int calc_area(rect r){
    r.area=r.length*r.breadth;
    return r.area;
}

int main(){
    rect a;
    a.getDimensions();
    cout<<"area is "<<calc_area(a);
}
