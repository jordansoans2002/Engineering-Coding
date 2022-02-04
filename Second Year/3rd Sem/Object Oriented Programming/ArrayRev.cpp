#include <iostream>
using namespace std;

int main(){
    cout<<"enter no of array elements ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter the array elements ";
    for(int i=n-1;i>=0;i--)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
