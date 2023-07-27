#include<stdio.h>
#define MAX 10


void display(int n,int w[MAX][MAX])
{
    int i,j;
    printf("The following matrix shows the shortest distances between every pair of vertices \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
                printf("%d\t", w[i][j]);
        }
        printf("\n");
    }

    //printf("\n The shortest paths are:\n");
        //for(i=1;i<=n;i++)
            //for(j=1;j<=n;j++)
            //{
               // if(i!=j)
                    //printf("\n <%d,%d>=%d",i,j,w[i][j]);
            //}
}

void floyds(int n,int w[MAX][MAX])
{
    int i, j, k;

    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (w[i][k] + w[k][j] < w[i][j])
                    w[i][j] = w[i][k] + w[k][j];
            }
        }
    }
    display(n,w);
}

void main()
{
    int i,n,W,j;
    int w[MAX][MAX], dist[MAX][MAX] ;

    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter the weight matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d",&w[i][j]);
        }
    }
    floyds(n,w);
}




