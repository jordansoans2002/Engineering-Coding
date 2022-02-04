#include <stdio.h>

int n,*arr;

void bubbleSort(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void selectionSort(){
    int i,j,min=0,temp;
    for(i=0;i<n;i++){
            min=i;
        for(j=i;j<n;j++){
            if(arr[min]>arr[j])
                min=j;
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

void insertionSort(){//logic not set
    int i,j,max,temp;
    for(i=0;i<n;i++){
        max=i;
        for(j=0;j<n-i;j++){
            if(arr[max]>arr[j])
                max=j;
        }
        temp=arr[max];
        arr[max]=arr[i];
        arr[i]=temp;
    }
}

void main()
