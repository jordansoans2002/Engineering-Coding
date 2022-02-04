#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *start=NULL,*current=NULL,*end=NULL;

int isEmpty(){
    if(start==NULL){
        printf("stack underflow\n");
        return 0;
    }
    return 1;
}

void queue(int no){
    Node *p=(Node*)malloc(sizeof(Node));
    current=start;
    p->data=no;
    if(start==NULL)
        start=p;
    else
    {
        while(current->next!=NULL)
            current=current->next;
        current->next=p;
    }
    p->next=NULL;
}

void traverse(){
    current=start;
    if(isEmpty()){
        while(current!=NULL){
            printf("%d ",current->data);
            current=current->next;
        }
    }
}

int dequeue(){
    if(isEmpty()){
        int t=start->data;
        current=start->next;
        free(start);
        start=current;
        return t;
    }
    return 0;
}

void peek(){
    printf("%d\n",start->data);
}

void main(){
    int n=0,num,loc,t;
    do{
        printf("select 1.queue 2.dequeue 3.traverse 4.peek 0 to exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
            break;

            case 1:
                printf("Enter value to be queued ");
                scanf("%d",&num);
                queue(num);
            break;

            case 2:
                t=dequeue();
                if(t)
                    printf("%d\n",t);
            break;

            case 3:
                traverse();
                printf("\n");
            break;

            case 4:
                peek();
            break;

            default:
                printf("invalid input\n");
        }
    }while(n!=0);
}
