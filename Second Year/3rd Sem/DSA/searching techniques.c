#include <stdio.h>

int n,*arr;

void sort(){
    for(int i=0;i<n;i++){
        int min=arr[i];
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min])
                min=j;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

int linearSearch(int f){
    for(int i=0;i<n;i++){
        if(arr[i]==f)
            return i+1;
    }
    return 0;
}

int binarySearch(int f){
    sort();
    int mid=n/2,ub=n-1,lb=0,k=0;
    while(ub>=lb){
        printf("%d",++k);
        mid=(ub+lb)/2;
        if(arr[mid]==f)
            return mid+1;
        else if(arr[mid]>f)
            ub=mid-1;
        else
            lb=mid+1;
    }
    return 0;
}

void main(){
    printf("enter the number of elements ");
    scanf("%d",&n);
    arr=(int*)calloc(n,sizeof(int));
    printf("enter the elements of the array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int f,ch,pos=0;
    printf("enter no to be found ");
    scanf("%d",&f);
    printf("enter 1 for linear search and 2 for binary search ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            pos=linearSearch(f);
            break;
        case 2:
            pos=binarySearch(f);
            break;
        default:
            printf("invalid choice");
    }
    if(pos)
        printf("\nElement found at %d position",pos);
    else
        printf("Element not found");
}
