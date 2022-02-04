#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *start=NULL,*current=NULL,*top=NULL;

void isEmpty()
{
    if(start==NULL)
        printf("is Empty");
}

void push(int no){
    Node *p=(Node*)malloc(sizeof(Node));
    current=start;
    p->data=no;
    if(start==NULL){
        start=p;
        top=p;
    }
    else
    {
        top->next=p;
        top=p;
    }
    p->next=NULL;
}

void pop(int n){
    printf("%d\n",top->data);
    if(n==2){
        if(top==start){
            free(start);
            start=NULL;
            top=start;
        }
        else{
            current=start;
            while(current->next->next!=NULL)
                current=current->next;
            current->next=NULL;
            free(top);
            top=current;
        }
    }
}

int traverse(int n,int f){
    current=start;int k=1;
    while(current!=NULL)
    {
        if(n==5)//disp function is called by user
            printf("%d ",current->data);
        if(n==6&&f==current->data)//search function is called by user
            return k;
        current=current->next;
        k++;
    }
    if(n==6)
        return -1;
    return (k-1);//normally return the nof elements
}

void main(){
    int n=0,num,loc,t;
    do{
        printf("select 1.push 2.pop 3.peek 4.count 5.traverse 6.search 0 to exit ");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
            break;

            case 1:
                printf("Enter value to be pushed ");
                scanf("%d",&num);
                push(num);
            break;

            case 2:
                if(start==NULL)
                    printf("stack underflow\n");
                else
                    pop(n);
            break;

            case 3:
                if(start==NULL)
                    printf("stack underflow\n");
                else
                    pop(n);
            break;

            case 4:
                printf("no of elements is %d \n",traverse(n,0));
            break;

            case 5:
                t=traverse(n,0);
                printf("\n");
            break;

            case 6:
                printf("Enter the element to be searched ");
                scanf("%d",&num);
                t=traverse(n,num);
                if(t!=-1)
                    printf("input number found at %d\n", t);
                else
                    printf("no not found\n");
            break;

            default:
                printf("invalid input\n");
        }
    }while(n!=0);
}
