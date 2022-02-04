#include <stdio.h>

int *a,n,s;

void sort(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("sorted array is\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

void search(){
    int ub=n,lb=0,mid;
    while(ub>=lb){
        mid=(ub+lb)/2;
        if(a[mid]==s){
            printf("number is found at position %d",(mid+1));
            break;
        }
        else if(a[mid]<s)
            lb=mid+1;
        else
            ub=mid-1;
    }
}

void binarySort(){
    int arr[n];
    arr[n/2]=a[n]
}

void main(){
    printf("enter the number of elements in the array\n");
    scanf("%d",&n);
    a=(int*)calloc(n,sizeof(int));
    printf("enter the elements of the array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort();
    printf("enter number to be found\n");
    scanf("%d",&s);
    search();
}
