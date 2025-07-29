//Dijkstras Algorithm
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n;
int cost[MAX][MAX];
void readGraph(){
	int i,j;
	FILE *fp=fopen("Dijkstra_Graph.txt","r");
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
int dist[MAX];   //dist +cost
int pred[MAX]; //parent
int mptSet[MAX];
int minVertex(){
	int i,j;
	int index=-1;
	int min=9999;
	for(i=0;i<n;i++){
		if(mptSet[i]==0 && min>dist[i]){
			min=dist[i];
			index=i;
		}
	}
	return index;
}
void Dijkstra(int r){
	int i,v;
	for(i=0;i<n;i++){
		dist[i]=9999;
		pred[i]=-1;
		mptSet[i]=0;
	}
	dist[r]=0;
	for(i=0;i<n;i++){
		int u=minVertex();
		mptSet[u]=1;
		for(v=0;v<n;v++){
			if(cost[u][v]!=0){
				if(mptSet[v]==0 && dist[v] > dist[u]+cost[u][v]){
					dist[v]=dist[u]+cost[u][v];
					pred[v]=u; //parent
				}	
			}
		}
	}
}
void path(int src, int dest){  //
	if(dest==src){
		printf("%c",src+'A');
		return;
	}
	path(src,pred[dest]); 
	printf("--->%c",dest+'A');
}
void pathCost(int src){ //0
	int i;
	for(i=0;i<n;i++){ // 0   1
		if(i!=src){ //  0!=1
			printf("\nCost of the path from %c to %c is %d \t Path : ",src+'A',i+'A',dist[i]);
			path(src,i);                        
			printf("\n");
		}
	}
}
int main(){
	readGraph();
	displayGraph();
	int src=0; 
	Dijkstra(src);
	printf("\n\n");
	int i;
	for(i=1;i<n;i++){
		printf("%d-->%d\n",i,pred[i]);
		printf("\t\t%d\n",dist[i]);
	}
	pathCost(src);
	return 0;
}
