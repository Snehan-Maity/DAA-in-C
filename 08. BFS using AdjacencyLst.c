//BFS using Adjacency List
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 20
int front = -1, rear = -1;
int Q[MAX];
int visited[MAX];
int n;
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* adjList[MAX];  // Array of pointers to linked lists
int isFull() {
    return (rear + 1 == MAX);
}
int isEmpty() {
    return (front == rear);
}
void enQueue(int item) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }
    Q[++rear] = item;
}
int deQueue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return INT_MAX;
    }
    return Q[++front];
}
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}
void readGraph() {
    FILE* fp = fopen("graph.txt", "r");
    if (fp == NULL) {
        printf("File open failed!!\n");
        exit(1);
    }
    fscanf(fp, "%d", &n);
	int i;
    for (i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }
    int src, dest;
    while (fscanf(fp, "%d", &src) != EOF) {
        while (1) {
            fscanf(fp, "%d", &dest);
            if (dest == -1)
                break;
            addEdge(src, dest);
        }
    }
    fclose(fp);
}
void displayGraph() {
	int i;
    printf("\nAdjacency List:\n");
    for (i = 0; i < n; i++) {
        printf("%d: ", i);
        Node* temp = adjList[i];
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\n");
}
void BFS(int v) {
    enQueue(v);
    visited[v] = 1;

    while (!isEmpty()) {
        int u = deQueue();
        printf("%c ", u + 'A');

        Node* temp = adjList[u];
        while (temp) {
            int w = temp->vertex;
            if (!visited[w]) {
                visited[w] = 1;
                enQueue(w);
            }
            temp = temp->next;
        }
    }
}
int main() {
    readGraph();
    displayGraph();
    int start;
    printf("Enter starting node index (0 to %d): ", n - 1);
    scanf("%d", &start);
    printf("BFS Traversal: ");
    BFS(start);
    return 0;
}
