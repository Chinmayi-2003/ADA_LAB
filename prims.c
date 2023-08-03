#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 10

int minKey(int key[], bool mstSet[], int n)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < n; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

int printMST(int parent[], int graph[V][V], int n)
{
    int weight = 0;
	printf("Edge \tWeight\n");
	for (int i = 1; i < n; i++)
		printf("%d - %d \t%d \n", parent[i], i,
			graph[i][parent[i]]);

    for(int i=1;i<n;i++){
        weight += graph[i][parent[i]];
    }
    printf("\nWeight is %d \n",weight);
}

void prims(int graph[V][V],int n)
{
	int parent[V];
	int key[V];
	bool mstSet[V];

	for (int i = 0; i < n; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;

	parent[0] = -1;

	for (int count = 0; count < n - 1; count++) {

		int u = minKey(key, mstSet, n);

		mstSet[u] = true;

		for (int v = 0; v < n; v++)

			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, graph, n);
}

int main()
{
    int graph[V][V],n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the weight matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    }

	prims(graph,n);
	return 0;
}

