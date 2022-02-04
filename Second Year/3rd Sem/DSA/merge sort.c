#include <stdio.h>

void mergeSort(){
    int i=0,j=0,k=0;
    while(k<c.length){
        if(a[i]>b[j]||j==b.length&&i<a.length)
            c[k++]=a[i++];
        if(b[j]>a[i]&&i==a.length&&j<b.length)
            c[k++]=b[j++];
    }
}
