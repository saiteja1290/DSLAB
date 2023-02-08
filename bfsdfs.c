#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t {
	int V; // No. of vertices
	bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Constructor
Graph* Graph_create(int V)
{
	Graph* g = malloc(sizeof(Graph));
	g->V = V;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			g->adj[i][j] = false;
		}
	}

	return g;
}

// Destructor
void Graph_destroy(Graph* g) { free(g); }

// function to add an edge to graph
void Graph_addEdge(Graph* g, int v, int w)
{
	g->adj[v][w] = true; // Add w to v’s list.
}

// prints BFS traversal from a given source s
void Graph_BFS(Graph* g, int s)
{
	bool visited[50];
	int queue[50];

	for (int i = 0; i < g->V; i++)
	{
		visited[i] = false;
	}

	int front = 0, rear = 0;
	visited[s] = true;
	queue[rear++] = s;
	
	
	while (front != rear)
	{
		s = queue[front++];
		printf("%d",s);

		for (int i = 0; i < g->V; i++)
		{
			if(g->adj[s][i] && !visited[i]){
				visited[i] = true;
				queue[rear++] = i;
			}
		}
		
	}
	
}
bool visiteddfs[50];
void Graph_DFS(Graph *g , int s){
	visiteddfs[s] = true;
	printf("%d",s);
	for (int i = 0; i < g->V; i++){
		if (!visiteddfs[i]){
			Graph_DFS(g,i);
			visiteddfs[i] = true;
		}
	}
}
// Driver program to test methods of graph struct
int main()
{
	for (int i = 0; i < 50; i++){
		visiteddfs[i] = false;
	}
	// Create a graph given in the above diagram
	Graph* g = Graph_create(4);
	Graph_addEdge(g, 0, 1);
	Graph_addEdge(g, 0, 2);
	Graph_addEdge(g, 1, 2);
	Graph_addEdge(g, 2, 0);
	Graph_addEdge(g, 2, 3);
	Graph_addEdge(g, 3, 3);

	printf("Following is Breadth First Traversal "
		"(starting from vertex 2) \n");
	Graph_BFS(g, 2);
	printf("\n");
	Graph_DFS(g,0);

	Graph_destroy(g);

	return 0;
}
