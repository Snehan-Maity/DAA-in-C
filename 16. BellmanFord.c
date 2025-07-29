//BellmanFord 
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n;
int dist[MAX];
int pred[MAX];
typedef struct edge{
	int v1,v2,w;   // A to B is 1    (0,1,1),(1,2,1),(1,5,5),........e[2].v1=1    v2=5  w=5
}edge;
edge e[10];  
int noe=0; // noe=8
void readGraph(){
	FILE *fp;
	int i,j,read,m=0;
	fp=fopen("Bellman_Graph.txt","r");
	if(fp==NULL){
		printf("FILE open failed\n");
		exit(1);
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++){    //0   1   2
		for(j=0;j<n;j++){    //0
			fscanf(fp,"%d",&read);   // 5
			if(read!=0){ //Counting the no of edges
				e[m].v1=i; // e[0]=(0,1,1)   e[1]=(1,2,1)   e[2]=(1,5,5)  e[3]
				e[m].v2=j; // 1
				e[m++].w=read; // 1
				noe++;   //3
			}
		}
	}
	fclose(fp);
	for(i=0;i<noe;i++){
		printf("(%c --> %c): %d\n",e[i].v1+65,e[i].v2+65,e[i].w); 
	}
	printf("\n");
}
int Bellman(int r){  //0
	int i,j;
	for(i=0;i<n;i++){
		dist[i]=9999;
		pred[i]=-1;
	}                                      // e[2].v1=1    v2=5  w=5
	dist[r]=0;  // dist[0]=0  
	for(i=0;i<n-1;i++){     //0
		for(j=0;j<noe;j++){     //0  1  2
			if(dist[e[j].v2]>dist[e[j].v1]+e[j].w){  // 9999 > 1+5=6
				dist[e[j].v2]=dist[e[j].v1]+e[j].w;   // dist[1]=1  dist[2]=2   dist[5]=6
				pred[e[j].v2]=e[j].v1;   // pred[1]=0   pred[2]=1   pred[5]=1
			}
		}
	}for(j=0;j<noe;j++){
		if(dist[e[j].v2]>dist[e[j].v1]+e[j].w){
			return 0;
		}
	}
	return 1;
}
void path(int src, int dest){
	if(dest==src){
		printf("%c",src+'A');
		return;
	}
	path(src,pred[dest]);
	printf("--->%c",dest+'A');
}
void pathCost(int src){
	int i;
	for(i=0;i<n;i++){
		if(i!=src){
			printf("\nCost of the path from %c to %c is %d \t Path : ",src+'A',i+'A',dist[i]);
			path(src,i);
			printf("\n");
		}
	}
}
int main(){
	readGraph();
	int src=0;
	int result=Bellman(src);  //Bellman(0)
	if(result==0){
		printf("\nNegative Cycle Exists !!");
	}
	else{
		pathCost(src);
	}
	return 0;
}
