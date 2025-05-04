#include<stdio.h>
#include<limits.h>
int p[]={2,3,4,2,3};
int M[20][20];
int S[20][20];
void MatrixChainOrder(){
	int i,len,k;
	int n=sizeof(p)/sizeof(p[0])-1;
	for(i=1;i<=n;i++){
		M[i][i]=0;
	}
	for(len=2;len<=n;len++){
		for(i=1;i<=n-len+1;i++){
			int j=i+len-1;
			M[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++){
				int cost=M[i][k] + M[k+1][j] + (p[i-1]*p[k]*p[j]);
				if(cost<M[i][j]){
					M[i][j]=cost;
					S[i][j]=k;
				}
			}
		}
	}
}
void POP(int i, int j){
	if(i==j){
		printf("A%d",i);
	}
	else{
		printf("(");
		POP(i,S[i][j]);
		POP(S[i][j]+1,j);
		printf(")");
	}
}
void printMTable(int n){
	int i,j,k;
	printf("***** M Table *****\n");
	for(i=1;i<=n;i++){
		for(k=1;k<i;k++){
			printf("%3c",' ');
		}
		for(j=i;j<=n;j++){
			printf("%3d",M[i][j]);
		}
		printf("\n");
	}
}
void printSTable(int n){
	int i,j,k;
	printf("***** S Table *****\n");
	for(i=1;i<=n;i++){
		for(k=1;k<=i;k++){
			printf("%3c",' ');
		}
		for(j=i+1;j<=n;j++){
			printf("%3d",S[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int n=sizeof(p)/sizeof(p[0])-1;
	MatrixChainOrder();
	printMTable(n);
	printSTable(n);
	POP(1,n);
	printf("\n");
	return 0;
}
