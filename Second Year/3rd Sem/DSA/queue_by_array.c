#include <stdio.h>

int arr[100];
int start=-1,end=-1;

void isEmpty(){
    if(end<=start){
        start=-1;
        end=-1;
    }
}

void queue(int n){
    if(end<99){
        arr[++end]=n;
    }
    else
        printf("stack overflow\n");
}

int dequeue(){
    if(end>start){
        return arr[++start];
    }
    else
        printf("stack underflow stack is empty\n");
    return -1;
}

void peek(){
    if(start<end)
        printf("%d\n",arr[start+1]);
    else
        printf("Stack is empty");
}

void main(){
    int c=0,n=0,t=0;
    do{
        isEmpty();
        printf("Select  1.queue 2.dequeue 3.peek 0 to exit\n");
        scanf("%d",&c);
        switch(c){
            case 0:
            break;

            case 1:
            printf("Enter the number to be queued ");
            scanf("%d",&n);
            queue(n);
            break;

            case 2:
            t=dequeue();
            if(t!=-1)
            printf("%d\n",t);
            break;

            case 3:
            peek();
            break;
        }
    }while(c!=0);
}
