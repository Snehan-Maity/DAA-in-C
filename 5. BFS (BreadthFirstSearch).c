//BFS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 20
int front = -1;
int rear = -1;
int Q[MAX];
int visited[MAX];
int n;
int weight[MAX][MAX]; 
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
void BFS(int v) {
    enQueue(v);
    visited[v]=1;
    while (!isEmpty()) {
        int u=deQueue();
        printf("%c ",u+'A');
		int w;
        for (w=0;w<n;w++) {
            if (weight[u][w] == 1 && visited[w] == 0) {
                visited[w] = 1;
                enQueue(w);
            }
        }
    }
}
void readGraph() {
    FILE *fp = fopen("BFS_Graph.txt", "r");
    if (fp == NULL) {
        printf("\nFile open failed!!\n");
        exit(1);
    }
    fscanf(fp,"%d",&n);  // Read number of vertices
	int i,j;
    for (i=0;i<n;i++) {
        visited[i]=0;
        for(j=0;j<n;j++) {
            fscanf(fp,"%d",&weight[i][j]);
        }
    }
    fclose(fp);
}
void displayGraph() {
	int i,j;
    printf("\nAdjacency Matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("%2d ", weight[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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

