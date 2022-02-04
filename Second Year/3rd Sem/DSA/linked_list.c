#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *start=NULL,*current=NULL;

void append(int no){
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

int traverse(int n,int f){
    current=start;int k=1;
    while(current!=NULL)
    {
        if(n==3)//disp function is called by user
            printf("%d ",current->data);
        if(n==5&&f==current->data)//search function is called by user
            return k;
        current=current->next;
        k++;
    }
    if(n==5)
        return -1;
    return (k-1);//normally return the nof elements
}

int delete(int loc){
    current=start;
    Node* q;
    if(loc==1){
        start=current->next;
        current=NULL;
        return 0;
    }
    for(int i=1;i<loc-1;i++)
    {
        if(current==NULL){
            printf("this position does not exist ");
            return (i-1);
        }
        current=current->next;
    }
    q=current->next;
    current->next=q->next;
    q=NULL;
    return 0;
}

int insert(int n,int loc){
    Node* p=(Node*)malloc(sizeof(Node));
    current=start;
    p->data=n;
    if(loc==0){
        p->next=start->next;
        start=p;
        return 0;
    }
    for(int i=1;i<loc;i++)
    {
        if(current==NULL){
            printf("this postition doesn't exist");
            return (i-1);
        }
        current=current->next;
    }
    p->next=current->next;
    current->next=p;
    return 0;
}

void reverse()
{
    Node *end=start,*t=start;
    current=start;
    while(current->next!=NULL)
        current=current->next;
    start=current;
    while(current!=t)
    {
        end=t;
        while(end->next->next!=NULL)
            end=end->next;
        current->next=end;
        end->next=NULL;
        current=end;
    }
}

void main(){
    int n=0,num,loc,t;
    do{
        printf("select 1.append 2.insert 3.traverse 4.count 5.search 6.reverse 7.delete 0 to exit ");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
            break;

            case 1:
                printf("Enter value to be appended ");
                scanf("%d",&num);
                append(num);
            break;

            case 2:
                printf("Enter number and location after which to be inserted ");
                scanf("%d %d",&num,&loc);
                t=insert(num,loc);
                if(t!=0)
                    printf("last position is %d\n",t);
                else
                    printf("inserted\n");
            break;

            case 3:
                t=traverse(n,0);
                printf("\n");
            break;

            case 4:
                printf("no of elements is %d \n",traverse(n,0));
                break;

            case 5:
                printf("Enter the element to be searched ");
                scanf("%d",&num);
                t=traverse(n,num);
                if(t!=-1)
                    printf("input number found at %d\n", t);
                else
                    printf("no not found");
            break;

            case 6:
                reverse();
            break;

            case 7:
                if(start==NULL)
                    printf("list is empty\n");
                else
                {
                    printf("Enter postion at which to be deleted ");
                    scanf("%d",&loc);
                    t=delete(loc);
                    if(t!=0)
                        printf("last position is %d \n",t);
                }
            break;

            default:
                printf("invalid input\n");
        }
    }while(n!=0);
}
