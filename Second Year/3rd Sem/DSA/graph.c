#include <stdio.h>

int a[10][10],sq[10],visited[10];
int top=-1,start=-1,end=0,n;

void dfs(int i){
    visited[i]=1;
    for(int j=1;j<=n;j++){
        if(a[i][j] && !visited[j]){
            printf("%d->%d\t",i,j);
            sq[++top]=j;
        }
    }
    if(top>-1)
        dfs(sq[top--]);
}

void bfs(int i){
    visited[i]=1;
    for(int j=1;j<=n;j++){
        if(a[i][j] && !visited[j]){
            printf("%d->%d \t",i,j);
            sq[end++]=j;
        }
    }
    if(start<end)
        bfs(start++);
}

void main(){
    printf("enter the no of nodes ");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    int i,j,ch;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    }
    printf("enter the starting node ");
    scanf("%d",&i);
    printf("enter 1 for dfs and 2 for bfs ");
    scanf("%d",&ch);
    if(ch==1) dfs(i);
    else if(ch==2) bfs(1);
    else printf("invalid option");
}
