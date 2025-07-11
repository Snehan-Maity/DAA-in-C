#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define V 4
int graph[V+1][V+1]={
					{0,0,0,0,0},
					{0,0,1,0,1},
					{0,1,0,1,0},
					{0,0,1,0,1},
					{0,1,0,1,0}
					};
int n=V;
int m;
int x[V+1]={0};
void nextValue(int k){
	while(1){
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0){
			return;
		}
		int j;
		for(j=1;j<k;j++){
			if(graph[j][k]==1 && x[j]==x[k]){
				break;
			}
		}
		if(j==k){
			return;
		}
	}
}
void printSolution(){
	int i;
	static int count;
	printf("Solution %d : ",++count);
	for(i=1;i<=n;i++){
		printf("%3d",x[i]);
	}
	printf("\n");
}
void mColoring(int k){  //mC(1)
	while(1){
		nextValue(k);
		if(x[k]==0){
			return;
		}
		if(k==n){
			printSolution();
		}
		else{
			mColoring(k+1);   //mC(2)
		}
	}
}
int main(){
	printf("Enter the number of colors : ");
	scanf("%d",&m);
	mColoring(1);
	return 0;
}
