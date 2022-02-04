#include <stdio.h>
int *a,n;
int partition(int lb,int ub){
    int p=a[lb];
    int i=lb+1;
    int j=ub;
    while(i<=j){
        while(a[i]<p&&i<ub)
            i++;
        while(a[j]>p)
            j--;
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }else
            break;
    }
    printf("i=%d j=%d\n",i,j);
    //pos for pivot is j
    a[lb]=a[j];
    a[j]=p;
    return j;
}

int partition2(int lb,int ub){
    int p=a[ub];
    for(int i=lb;i<=ub;i++){
        //if(a[i]>)
    }
}

void quickSort(int lb,int ub){
    if(ub<lb)
        return;
    int p=partition(lb,ub);
    printf("\narray is ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("p=%d a[p]=%d",p,a[p]);
    quickSort(lb,p-1);
    quickSort(p+1,ub);
}

void main(){
    printf("enter max no elements ");
    scanf("%d",&n);
    a=(int*)calloc(n,sizeof(int));
    printf("enter %d numbers ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    quickSort(0,n-1);
    printf("\nsorted array is\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
