#include <stdio.h>
#include <stdlib.h>
#include "queuelinlist.h"
#include "stack.h"

// Structure for a graph node
struct Node {
    int data;
    struct Node* next;
};

// Structure for a graph
struct Graph {
    int V; // Number of vertices
    struct Node** adjList; // Adjacency list
};

// Function to create a new graph node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; ++i)
        graph->adjList[i] = NULL;

    return graph;
}

// Function to add a directed edge to the graph 
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest. A new node is added to the adjacency list of src. The node is added at the beginning
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}


// BFS
void BFS(struct Graph* graph, int startVertex) {
    int visited[7] = {0};
    int i, j;
    enqueue(startVertex);
    visited[startVertex] = 1;
    while (!isEmpty()) {
        i = dequeue();
        printf("%d ", i);
        for (j = 1; j < graph->V; j++) {
            if (graph->adjList[i][j] == 1 && visited[j] == 0) {
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
}

//DFS
void DFS(struct Graph* graph, int startVertex) {
    int visited[7] = {0};
    int i, j;
    push(startVertex);
    visited[startVertex] = 1;
    while (!isEmptyS()) {
        i = pop();
        printf("%d ", i);
        for (j = 1; j < graph->V; j++) {
            if (graph->adjList[i][j] == 1 && visited[j] == 0) {
                push(j);
                visited[j] = 1;
            }
        }
    }
}

//Topological sort
void Topo(struct Graph* graph, int startVertex) {
    static int visited[7] = {0};
    int j;
    if (visited[startVertex] == 0) {
        printf("%d ", startVertex);
        visited[startVertex] = 1;
        for (j = 1; j < graph->V; j++) {
            if (graph->adjList[startVertex][j] == 1 && visited[j] == 0) {
                Topo(graph, j);
            }
        }
    }
}

// // Function to print the graph
// void printGraph(struct Graph* graph) {
//     int v;
//     for (v = 0; v < graph->V; v++) {
//         struct Node* temp = graph->adjList[v];
//         printf("\n Adjacency list of vertex %d\n ", v);
//         while (temp) {
//             printf("%d -> ", temp->data);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
// }

// Driver program to test above functions
int main() {
    // create the graph given in above fugure
    int V = 7;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 6);
    //BFS
    printf("BFS: ");
    BFS(graph, 1);
    printf("\n");
    //DFS
    printf("DFS: ");
    DFS(graph, 1);
    printf("\n");
    //Topological sort
    printf("Topological sort: ");
    Topo(graph, 1);
    printf("\n");
    printGraph(graph);
}