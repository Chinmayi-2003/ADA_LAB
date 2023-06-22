#include<stdio.h>

void dfs(int v, int n, int g[n][n], int visited [n]){
    int i;
    printf("\n %d",v);
    visited[v]=1;
    for(i=1;i<=n;i++){
        if(g[v][i]&& !visited[i]){
            dfs(i,n,g, visited);
        }
    }

}

void main(){
    int i,j,n,snode;
    printf("enter the number of nodes ");
    scanf("%d",&n);
    int g[n][n], visited[n];
    for(i=1;i<=n;i++){
            visited[i]=0;
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
    dfs(snode,n,g, visited);
}
