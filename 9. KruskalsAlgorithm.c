//Kruskals Algorithm
#include<stdio.h>
struct Edge{
	int v1;
	int v2;
	int weight;
};
struct Edge e[]={{0,0,0},{1,2,7},{1,4,8},{2,4,3},{2,3,6},{3,5,2},{3,4,4},{4,5,3},{5,6,2},{3,6,5}};
int noE=9;
int noV=6;
void display(){
	int i;
	for(i=1;i<=noE;i++){
		printf("(%c %c)==>%d\n",e[i].v1-1+'A',e[i].v2-1+'A',e[i].weight);
	}
	printf("\n");
}
void bubble(){
	int i,j;
	for(i=1;i<=noE-1;i++){
		for(j=1;j<=noE-i;j++){
			if(e[j].weight>e[j+1].weight){
				struct Edge temp=e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
			}
		}
	}
}
int parent[100];
int find(int v){
	while(parent[v]>0){
		v=parent[v];
	}
	return v;
}
void simpleUnion(int u,int v){
	parent[v]=u;
}
int spT[20][3];
int treeEdge=0;
void Kruskal(){
	int i;
	bubble();
	display();
	for(i=1;i<=noV;i++){
		parent[i]=-1;
	}
	for(i=1;i<=noE;i++){
		int u=find(e[i].v1);
		int v=find(e[i].v2);
		if(u!=v){
			simpleUnion(u,v);
			spT[treeEdge][0]=e[i].v1;
			spT[treeEdge][1]=e[i].v2;
			spT[treeEdge++][2]=e[i].weight;
		}
	}
	int cost=0;
	for(i=0;i<treeEdge;i++){
		printf("(%c %c)==>%d\n",spT[i][0]-1+'A',spT[i][1]-1+'A',spT[i][2]);
		cost+=spT[i][2];
	}
	printf("\nTotal Cost : %d",cost);
}
int main(){
	Kruskal();
	return 0;
}
