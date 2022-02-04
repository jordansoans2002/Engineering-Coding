#include <stdio.h>
int top=-1,max;

int size(){
    return (top+1);
}

int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

int isFull(){
    if(top==max)
        return 1;
    else
        return 0;
}
int peek(int arr[]){
    if(isEmpty()){
        printf("Stack is empty\n");
        return -1;
    }
    else
        return arr[top];
}

void display(int arr[]){
    if(isEmpty())
        printf("Stack is empty\n");
    else{
        for(int i=0;i<=top;i++)
            printf("%d ",arr[i]);
    }
}

int pop(int arr[]){
    if(isEmpty()){
        printf("Stack is empty\n");
        return -1;
    }
    else
        return arr[top--];
}

void push(int arr[],int n){
    if(isFull())
        printf("Stack is full\n");
    else
        arr[++top]=n;
}

void main()
{
    printf("Enter the maximum size of the stack ");
    scanf("%d",&max);
    int arr[--max],n=10,num;
    while(n!=0){
        printf("Enter 1 to push, 2 to pop, 3 to peek, 4 to display stack, 5 to see size 0 to stop\n");
        scanf("%d",&n);
        switch(n){
            case 0:
            break;
            case 1:
                printf("Enter number to be pushed ");
                scanf("%d",&num);
                push(arr,num);
                break;
            case 2:
                printf("%d\n",pop(arr));
                break;
            case 3:
                printf("%d\n",peek(arr));
                break;
            case 4:
                display(arr);
                break;
            case 5:
                printf("%d\n",size());
                break;
            default:
                printf("invalid choice please re enter");
        }
    }
}
