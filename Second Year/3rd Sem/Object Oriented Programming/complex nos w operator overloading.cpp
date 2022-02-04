#include<math.h>
#include <iostream>
using namespace std;

class Complex{
public:
    int r,i;
    Complex(){
        r=0;i=0;
    }
    Complex(int r1,int i1){
        r=r1;
        i=i1;
    }
    void input(){
        cout<<"Enter the real and imaginary values: ";
        cin>>r>>i;
    }
    void output(){
        cout<<r<<"+"<<i<<"i";
    }

    Complex operator+(Complex z){
        int sr=r+z.r;
        int si=i+z.i;
        Complex s(sr,si);
        return s;
    }
    Complex operator-(Complex z){
        int sr=r-z.r;
        int si=i-z.i;
        return Complex(sr,si);
    }
};

int main(){
    Complex z1,z2,zs;
    z1.input();
    z2.input();
    zs=z1+z2;//zs=operator+(operator+(z1+z2),z3),z4;
    cout<<"\nsum: ";
    zs.output();
    Complex zd=z1-z2;
    cout<<"\ndifference: ";
    zd.output();
}
