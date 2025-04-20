//Floyd-Warshall
#include<stdio.h>
#include<Stdlib.h>
#define MAX 10
int n;
int count=0;
int cost[MAX][MAX];
int dist[MAX][MAX];
int parent[MAX][MAX];
void display(int arr[][MAX]){
	int i,j;
	printf("Matrix D%d :\n\n",count++);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%4d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
void readGraph(){
	int i,j;
	FILE *fp=fopen("FW_Graph.txt","r");
	if(fp==NULL){
		printf("\nFile open failed !!");
		exit(1);
	}
	else{
		fscanf(fp,"%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				fscanf(fp,"%d",&cost[i][j]);
			}
		}
	}
	fclose(fp);
}
void FloydWarshall(){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			dist[i][j]=cost[i][j];
			if(cost[i][j]==0 || cost[i][j]==9999){
				parent[i][j]=-1;
			}
			else{
				parent[i][j]=i;
			}
		}
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					parent[i][j]=parent[k][j];
				}
			}
		}
		display(dist);
	}
}
void path(int src, int dest){
	if(src==dest){
		printf("%c",src+'A');
		return;
	}
	path(src,parent[src][dest]);
	printf("--->%c",dest+'A');
}
void pathCost(int src){
	int i;
	for(i=0;i<n;i++){
		if(i!=src){
			printf("\nCost of the path from %c to %c is %d\t Path = ",src+'A',i+'A',dist[src][i]);
			path(src,i);
			printf("\n");
		}
	}
}
int main(){
	readGraph();
	display(cost);
	FloydWarshall();
	pathCost(0);
	return 0;
}
