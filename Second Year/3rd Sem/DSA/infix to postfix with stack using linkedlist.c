/*
9165
Expt 6- infix to postfix using stack by linked list
Jordan Soans
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data;
    struct Node* next;
}Node;

Node *start,*top,*current;

int isEmpty()
{
    if(start==NULL)
        return 1;
    return 0;
}

void push(char ch){
    Node *p=(Node*)malloc(sizeof(Node));
    current=start;
    p->data=ch;
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

char pop(){
    char c=top->data;
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
    return c;
}

char peek(){
    if(!(isEmpty(start)))
        return top->data;
}

int getPriority(char c){
    if(c=='(')
        return 0;
    else if(c=='+'||c=='-')
        return 1;
    else if(c=='*'||c=='/'||c=='%')
        return 2;
    else if(c=='^')
        return 3;
    else
        return -1;
}
void main(){
    char ex[20];
    printf("Enter the expression\n");
    scanf("%s",ex);
    int i,t=0;char sy;
    for(i=0;i<strlen(ex);i++)
    {
        sy=ex[i];
        if((int)sy>=65&&(int)sy<=90||(int)sy>=97&&(int)sy<=122)
            printf("%c ",sy);

        else if(sy=='('||sy=='['||sy=='{'){
            push(sy);
        }

        else if(sy==')'||sy==']'||sy=='}'){
            char syop='\0';
            switch(sy)
            {
                case ')':
                    syop='(';
                    break;
                case ']':
                    syop='[';
                    break;
                case '}':
                    syop='{';
                    break;
                default:
                    printf("invalid symbol");
                    break;
            }
            while(peek()!='(')
                printf("%c ",pop());
            pop();
        }

        else if(sy=='+'||sy=='-'||sy=='*'||sy=='/'||sy=='%'||sy=='^'){
            while(getPriority(peek())>=getPriority(sy))
                printf("%c ",pop());
            push(sy);
        }
        else{
            printf("invalid symbol \"%c\" ",sy);
            break;
        }
    }
    while(!(isEmpty())){
        printf("%c",pop());
    }
    //printf("postfix: ");
    //t=traverse(startPost,topPost,5,0);
}
