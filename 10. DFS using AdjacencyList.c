//DFS using Adjacency List
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int top = -1;
int stack[MAX];
int visited[MAX];
int n;
struct Node {
    int vertex;
    struct Node* next;
};
struct Node* adjList[MAX];  // Adjacency list array
int isEmpty() {
    return (top == -1);
}
int isFull() {
    return (top == MAX - 1);
}
void push(int item) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = data;
    newNode->next = NULL;
    return newNode;
}
void addEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}
void readGraph() {
    FILE* fp = fopen("graph.txt", "r");
    if (fp == NULL) {
        printf("File open failed!\n");
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
            if (dest == -1) break;
            addEdge(src, dest);
        }
    }
    fclose(fp);
}
void displayGraph() {
    printf("\nAdjacency List:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adjList[i];
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\n");
}
void DFS(int start) {
    push(start);
    while (!isEmpty()) {
        int u = pop();
        if (!visited[u]) {
            visited[u] = 1;
            printf("%c ",u+'A');
    	}
        struct Node* temp = adjList[u];
        while (temp) {
            int w = temp->vertex;
            if (!visited[w]) {
                push(w);
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
    printf("DFS Traversal: ");
    DFS(start);
    return 0;
}

