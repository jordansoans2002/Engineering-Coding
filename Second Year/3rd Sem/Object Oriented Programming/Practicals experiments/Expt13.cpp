#include<iostream>
using namespace std;
int main(){
    int a,b;
    std::cout<<"Enter two numbers\n";
    cin>>a>>b;
    cout<<"sum of "<<a<<" and "<<b<<" is "<<(a+b);
    int temp=a;
    a=b;
    b=temp;
    cout<<"\na = "<<a<<" and  b = "<<b;
    return 0;
}
/*
Enter two numbers
15 20
sum of 15 and 20 is 35
a = 20 and  b = 15
*/
