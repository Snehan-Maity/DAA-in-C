//DFS (DepthFirstSearch)
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int stack[MAX];
int top = -1;
int visited[MAX];
int weight[MAX][MAX];
int n;
void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
int isStackEmpty() {
    return top == -1;
}
void DFS(int v) {
    push(v);
    visited[v] = 1;

    while (!isStackEmpty()) {
        int u = pop();
        printf("%c ",u+'A');
		int w;
        for (w=n-1;w>=0;w--) {
            if (weight[u][w] == 1 && visited[w] == 0) {
                push(w);
                visited[w] = 1;
            }
        }
    }
}
void readGraph() {
    FILE *fp = fopen("DFS_Graph.txt", "r");
    if (fp == NULL) {
        printf("\nFile open failed!!\n");
        exit(1);
    }
    fscanf(fp,"%d",&n);
	int i,j;
    for(i=0;i<n;i++) {
        visited[i] = 0;
        for (j=0;j<n;j++) {
            fscanf(fp, "%d", &weight[i][j]);
        }
    }
    fclose(fp);
}
void displayGraph() {
    printf("\nAdjacency Matrix:\n");
    int i,j;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("%2d ",weight[i][j]);
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
    printf("DFS Traversal: ");
    DFS(start);
    return 0;
}

