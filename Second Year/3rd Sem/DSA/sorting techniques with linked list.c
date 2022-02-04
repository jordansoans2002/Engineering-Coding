#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *prev;
    struct node *next;
    int data;
}node;

node *start,*current;

void append(int d){
    node *n=(node*)malloc(sizeof(node));
    n->data=d;
    n->next=NULL;
    current=start;
    if(start==NULL){
        start=n;
        n->prev=NULL;
    }
    else{
        while(current->next!=NULL)
            current=current->next;
        current->next=n;
        n->prev=current;
    }
}

void traverse(){
    current=start;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
void dispRev(){
    current=start;
    while(current->next!=NULL)
        current=current->next;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->prev;
    }
}

void bubbleSort(){
    current=start;
    node *j=start;int t;
    while(current->next!=NULL){
        j=start;
        while(j->next!=NULL){
            if(j->data>j->next->data){
                 t=j->data;
                 j->data=j->next->data;
                 j->next->data=t;
            }
            j=j->next;
       }
       current=current->next;
    }
}

void selectionSort(){
    current=start;
    node *min,*currentSort;int t;
    while(current!=NULL){
        min=current;
        currentSort=current->next;
        while(currentSort!=NULL){
            if(min->data>currentSort->data)
                min=currentSort;
            currentSort=currentSort->next;
        }
        if(min!=current){
            t=min->data;
            min->data=current->data;
            current->data=t;
        }
        current=current->next;
    }
}

void insertionSort(){
    current=start->next;
    node *j=start;
    int t;
    while(current!=NULL){
        t=current->data;
        while(j!=NULL){
            if(j->data>t){
                j->next->data=j->data;
                j->data=t;
            }
            j=j->prev;
        }
        j=current;
        current=current->next;
    }
}

void main(){
    int n=0,num,loc,t;
    do{
        printf("select 1.append 2.insert 3.traverse 4.sort 0 to exit ");
        scanf("%d",&n);
        if(start==NULL&&n!=1){
            printf("invalid input please re enter\n");
            continue;
        }
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
                //t=insert(num,loc);
                if(t!=0)
                    printf("last position is %d\n",t);
                else
                    printf("inserted\n");
            break;

            case 3:
                traverse();
            break;

            case 4:
                printf("1.selection 2.bubble 3.insertion ");
                int ch;
                scanf("%d",&ch);
                switch(ch){
                    case 1:
                        selectionSort();
                    break;
                    case 2:
                        bubbleSort();
                    break;
                    case 3:
                        insertionSort();
                    break;
                    default:
                        printf("invalid selection");
                }
                traverse();
            break;

            case 5:
                dispRev();
                printf("\n");
            break;

            default:
                printf("invalid input\n");
        }
    }while(n!=0);
}
