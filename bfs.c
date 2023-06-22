#include<stdio.h>
int front = 0, rear =-1;
void bfs(int v, int n, int g[n][n], int visited [n], int queue[n]){
    int i;
    visited[v]=1;
    printf("%d\n",v);
    queue[++rear]=v;
    while(front<=rear){
    int temp = queue[front++];
    for(i=1;i<=n;i++){
    if(g[temp][i]&& !visited[i]){
        printf("%d\n",i);
    visited[i]=1;
    queue[++rear]=i;
    }
    }
    }
}

void main(){
    int i,j,n,snode;
    printf("enter the number of nodes ");
    scanf("%d",&n);
    int g[n][n], visited[n],queue[n];
    for(i=1;i<=n;i++){
            visited[i]=0;
            queue[i]=0;
        for(j=1;j<=n;j++)
            g[i][j]=0;
    }
    printf("Enter the matrix\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
          scanf("%d",&g[i][j]);
    }
    printf("enter the start nodes ");
    scanf("%d",&snode);

    printf("BFS order\n");
    bfs(snode,n,g, visited, queue);
}
