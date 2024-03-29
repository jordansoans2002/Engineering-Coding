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

void bfs(int i,int f){
    visited[i]=1;
    if(i==f){
        for(int k=1;k<=n;k++){
            // printf("%d sq\n",sq[k]);
            // printf("%d vis\n",visited[k]);
            if(visited[k]==1)
                printf("%d order",k);
        }
    }
    for(int j=1;j<=n;j++){
        if(a[i][j] && !visited[j]){
            //printf("%d->%d \t",i,j);
            sq[end++]=j;
        }
    }
    if(start<end)
        bfs(start++,f);
}

void main(){
    printf("enter the no of nodes ");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    int i,j,ch,f;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("enter the starting node ");
    scanf("%d",&i);
    printf("enter 1 for dfs and 2 for bfs ");
    scanf("%d",&ch);
    printf("enter target node ");
    scanf("%d",&f);
    if(ch==1) dfs(i);
    else if(ch==2) bfs(1,f);
    else printf("invalid option");
}
