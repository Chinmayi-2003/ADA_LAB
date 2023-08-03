#include<stdio.h>
#include <stdbool.h>
#define INT_MAX 99
#define V 5
int n;
int parent[V];
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskalMST(int cost[][V])
{
    int mincost = 0;

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edge_count = 0;
    while (edge_count < V - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        printf("Edge %d:(%d, %d) cost:%d \n",
               edge_count++, a, b, min);
        mincost += min;
    }
    printf("\n Minimum weight= %d \n", mincost);

}

int main()
{

    int cost[V][V];
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the weight matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    }

    kruskalMST(cost);

    return 0;
}
