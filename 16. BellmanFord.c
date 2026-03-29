//BellmanFord
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define INF 9999

int n;
int dist[MAX];
int pred[MAX];

typedef struct edge{
    int v1,v2,w;
} edge;

edge e[10];
int noe = 0;

void readGraph(){
    FILE *fp;
    int i,j,read,m=0;

    fp = fopen("Bellman_Graph.txt","r");
    if(fp==NULL){
        printf("FILE open failed\n");
        exit(1);
    }

    fscanf(fp,"%d",&n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            fscanf(fp,"%d",&read);
            if(read != 0){
                e[m].v1 = i;
                e[m].v2 = j;
                e[m].w  = read;
                m++;
                noe++;
            }
        }
    }

    fclose(fp);

    for(i=0;i<noe;i++){
        printf("(%c --> %c): %d\n", e[i].v1+65, e[i].v2+65, e[i].w);
    }
    printf("\n");
}

int Bellman(int r){
    int i,j;

    for(i=0;i<n;i++){
        dist[i] = INF;
        pred[i] = -1;
    }

    dist[r] = 0;

    for(i=0;i<n-1;i++){
        for(j=0;j<noe;j++){
            // FIX: relax only if source vertex is reachable
            if(dist[e[j].v1] != INF && dist[e[j].v2] > dist[e[j].v1] + e[j].w){
                dist[e[j].v2] = dist[e[j].v1] + e[j].w;
                pred[e[j].v2] = e[j].v1;
            }
        }
    }

    for(j=0;j<noe;j++){
        // FIX: same reachability check for negative-cycle test
        if(dist[e[j].v1] != INF && dist[e[j].v2] > dist[e[j].v1] + e[j].w){
            return 0;
        }
    }

    return 1;
}

void path(int src, int dest){
    if(dest == src){
        printf("%c", src+'A');
        return;
    }

    // FIX: unreachable node protection
    if(dest == -1){
        return;
    }

    path(src, pred[dest]);
    printf("--->%c", dest+'A');
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

    int src = 0;
    int result = Bellman(src);

    if(result == 0){
        printf("\nNegative Cycle Exists !!");
    }
    else{
        pathCost(src);
    }

    return 0;
}
