#include <stdbool.h>
#include <stdio.h>
#define MAX 999
int V;
int parents[50], noParent=-1;

int minDistance(int dist[], bool picked[])
{
	int min = MAX, min_index;

	for (int v = 0; v < V; v++)
		if (picked[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
void printPath(int vertx,int parents[V])
{
	if (vertx == noParent) {
		return;
	}
	printPath(parents[vertx], parents);
	printf("%d  ",vertx);
}
void printSolution(int dist[])
{
	printf("\nVertex \t\t Distance from source\t\tPath\n");
	for (int i = 0; i < V; i++){
        printf("  %d \t\t\t  %d \t\t\t", i, dist[i]);
		printPath(i,parents);
		printf("\n");
	}
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];

	bool picked[V];
	for (int i = 0; i < V; i++)
		dist[i] = MAX, picked[i] = false;

	dist[src] = 0;
    parents[0]=noParent;
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, picked);

		picked[u] = true;

		for (int v = 0; v < V; v++){
            if (!picked[v] && graph[u][v]
				&& dist[u] != MAX
				&& dist[u] + graph[u][v] < dist[v]){
				    dist[v] = dist[u] + graph[u][v];
				parents[v]=u;
				}
		}
	}

	printSolution(dist);
}

int main()
{
    printf("Enter the number of vertices\n");
    scanf("%d",&V);
	int graph[V][V],j;
	printf("Enter the matrix\n");
	for(int i=0;i<V;i++){
        for(j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
	}

	dijkstra(graph, 0);

	return 0;
}
