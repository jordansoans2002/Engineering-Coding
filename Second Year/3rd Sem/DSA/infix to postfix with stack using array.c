#include <stdio.h>
#include <string.h>
//char post[10];
char stack[50];
int top=-1;//,postTop=-1;

void push(char c){
    if(top==50){
        printf("stack overflow");
    }
    else{
        stack[++top]=c;
    }
    /*printf("%d ",top);
    for(int i=0;i<=top;i++) printf("%d ",stack[i]);
    printf("\n");*/
    //traverse(stack,top);
}

char peek(){
    return stack[top];
}
char* pop(){
    if(top==-1){
        printf("stack underflow");
        return '\0';
    }
    else{
        return stack[top--];
    }
}

int getPriority(char ch){
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/'||ch=='%')
        return 2;
    else if(ch=='^')
        return 3;
    else if(ch=='(')
        return 0;
    else
        return -1;
}

void traverse(){
    for(int i=0;i<=top;i++)
        printf("%c ",stack[i]);
    printf("\n");
}

void main(){
    printf("enter expression ");
    char s[50];
    scanf("%s",s);
    push('(');
    strcat(s,")");
    char c,p;
    for(int i=0;i<strlen(s);i++){
        c=s[i];
        if((int)c>=97&&(int)c<=122){
            printf("%c ",c);
        }
        else if(c=='('){
            push('(');
        }
        else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='^'){
            while(getPriority(peek())>=getPriority(c)&&top!=-1){
                //printf(" pop op %d",top);
                printf("%c ",pop());
            }
            push(c);
            //traverse();
        }
        else if(c==')'){
            //printf("\n %d %c \n",top,p);
            while(peek()!='('&&top!=-1){
                printf("%c ",pop());
            }
            if(peek()=='(')
                pop();
            //traverse();
        }
        else{
            printf("invalid symbol %c \n",c);
        }
        //printf("\ni=%d %d ",i,top);traverse();
    }
    while(top!=-1&&peek()!='('){
        printf("%c ",pop());
    }
    //traverse();
}

