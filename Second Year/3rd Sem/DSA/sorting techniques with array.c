#include <stdio.h>

int *arr;int n;

void bubbleSort(){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
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
        for(j=i+1;j<n;j++){
            if(arr[min]>arr[j])
                min=j;
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

void insertionSort(){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void main(){
    printf("Enter number of elements ");
    scanf("%d",&n);
    arr=(int*)calloc(n,sizeof(int));
    printf("enter the elements of the array");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int ch;
    printf("enter 1.bubble sort 2.selection sort 3.insertion sort ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            bubbleSort();
        break;

        case 2:
            selectionSort();
        break;

        case 3:
            insertionSort();
        break;

        default:
            printf("invalid option");
    }
    printf("the sorted array is\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
