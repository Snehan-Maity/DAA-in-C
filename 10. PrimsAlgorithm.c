//Prims Algorithm
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n;
int weight[MAX][MAX];  //2D array
void readGraph(){
	int i,j;
	FILE *fp=fopen("Prims_Graph.txt","r");
	if(fp==NULL){
		printf("\nFile open failed !!");
		exit(1);
	}
	fscanf(fp,"%d",&n);  // n=6
	for(i=0;i<n;i++){ 
		for(j=0;j<n;j++){
			fscanf(fp,"%d",&weight[i][j]);
		}
	}
	fclose(fp);
}
void displayGraph(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d",weight[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
int key[MAX];
int parent[MAX];
int mstSet[MAX];
int minKey(){
	int i;
	int index=-1;
	int min=9999; 
	for(i=0;i<n;i++){ // 0 1  2  3 4  5
		if(mstSet[i]==0 && key[i]<min){   // 3 < 6 ??
			min=key[i]; // min = 3
			index=i; //  index = 3 (D)
		}
	}
	return index; //3
}
void Prims(int start){
	int i,v;
	for(i=0;i<n;i++){
		key[i]=9999;
		parent[i]=-1;
		mstSet[i]=0;
	}
	key[start]=0; //key[A]=0
	for(i=0;i<n;i++){  // 0  1  2   3   4
		int u=minKey(); //0   1   3  5
		mstSet[u]=1; //mst[A]=1   mst[B]=1   mst[D]=1   mst[E]=1
		for(v=0;v<n;v++){  // adjacent of u 
			if(weight[u][v]!=0){
				if(mstSet[v]==0 && key[v]>weight[u][v]){ // 4>2
					key[v]=weight[u][v]; // key[B]=7   //key[D]=3  key[C]=2   key[E]=3   key[F]=2
					parent[v]=u; // parent[B]=A  // parent[D]=B   parent[C]=D  parent[E]=D p[F]=E
				}
			}
		}
	}
}
void displayTree(){
	int i,c=0;
	for(i=0;i<n;i++){  //0  1  2  3
		if(parent[i]!=-1){  // parent[3] = 4
			printf("(%c %c)==>%d\n",parent[i]+'A',i+'A',weight[parent[i]][i]); //(A B)==> 7
			c=c+weight[parent[i]][i];           // (E C) ==> 2
		}
	}
	printf("\nTotal Cost : %d",c);
}
int main(){
	readGraph();  //everything is stored in weight
	displayGraph();
	Prims(0); 
	displayTree();
	return 0;
}
