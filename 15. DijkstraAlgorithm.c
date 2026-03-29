//Dijkstras Algorithm
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define INF 9999

int n;
int cost[MAX][MAX];

void readGraph(){
    int i,j;
    FILE *fp = fopen("Dijkstra_Graph.txt","r");

    if(fp==NULL){
        printf("\nFile open failed !!");
        exit(1);
    }

    fscanf(fp,"%d",&n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            fscanf(fp,"%d",&cost[i][j]);
        }
    }

    fclose(fp);
}

void displayGraph(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%3d",cost[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int dist[MAX];
int pred[MAX];
int mptSet[MAX];

int minVertex(){
    int i;
    int index = -1;
    int min = INF;

    for(i=0;i<n;i++){
        if(mptSet[i]==0 && dist[i] < min){
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void Dijkstra(int r){
    int i,v;

    for(i=0;i<n;i++){
        dist[i] = INF;
        pred[i] = -1;
        mptSet[i] = 0;
    }

    dist[r] = 0;

    for(i=0;i<n;i++){
        int u = minVertex();

        // FIX: if no reachable unvisited vertex remains
        if(u == -1){
            break;
        }

        mptSet[u] = 1;

        for(v=0;v<n;v++){
            if(cost[u][v] != 0){
                if(mptSet[v] == 0 && dist[u] != INF && dist[v] > dist[u] + cost[u][v]){
                    dist[v] = dist[u] + cost[u][v];
                    pred[v] = u;
                }
            }
        }
    }
}

void path(int src, int dest){
    if(dest == src){
        printf("%c", src + 'A');
        return;
    }

    // FIX: unreachable node protection
    if(dest == -1){
        return;
    }

    path(src, pred[dest]);
    printf("--->%c", dest + 'A');
}

void pathCost(int src){
    int i;

    for(i=0;i<n;i++){
        if(i != src){
            if(dist[i] == INF){
                printf("\nCost of the path from %c to %c is INF \t Path : No path\n",
                       src+'A', i+'A');
            }
            else{
                printf("\nCost of the path from %c to %c is %d \t Path : ",
                       src+'A', i+'A', dist[i]);
                path(src, i);
                printf("\n");
            }
        }
    }
}

int main(){
    readGraph();
    displayGraph();

    int src = 0;
    Dijkstra(src);

    printf("\n\n");

    int i;
    for(i=1;i<n;i++){
        printf("%d-->%d\n", i, pred[i]);
        if(dist[i] == INF)
            printf("\t\tINF\n");
        else
            printf("\t\t%d\n", dist[i]);
    }

    pathCost(src);
    return 0;
}
