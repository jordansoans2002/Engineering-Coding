#include <iostream>
using namespace std;

void one(){
    cout<<"Enter a number ";
    int a;
    cin>>a;
    if(a%2)
        cout<<a<<" is an odd number";
    else
        cout<<a<<" is an even number";

}

void two(){
    cout<<"Enter 3 numbers to be compared\n";
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b||b==c||c==a)
        cout<<"some numbers are equal";
    else if(a>b&&a>c)
        cout<<a<<" is largest";
    else if(b>c)
        cout<<b<<" is largest";
    else
        cout<<c<<" is largest";

}

int main(){
	one();
	cout<<"\n\n";
	two();
	return 1;
}

/*
Enter a number 10
10 is an even number

Enter 3 numbers to be compared
10 15 20
20 is largest
*/
