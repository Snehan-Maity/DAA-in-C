//N-Queen
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int n,c=0,flag=0;
int x[MAX]={0};
int placed(int k, int i){
	int j;
	for(j=1;j<k;j++){
		if(x[j]==i | abs(j-k)==abs(x[j]-i)){
			return 0;
		}
	}
	return 1;
}
void displayMat(int x[n]){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(x[i]==j){
				printf("Q ");
			}
			else{
				printf(". ");
			}
		}
		printf("\n");
	}
	printf("\n");
}
void display(int x[n]){
	int i;
	c++;
	printf("Solution %d : ",c);
	for(i=1;i<=n;i++){
		printf("%3d",x[i]);
	}
	printf("\n\n");
	displayMat(x);
}
void nQueen(int k, int n){
	int i;
	for(i=1;i<=n;i++){
		if(placed(k,i)){
			x[k]=i;
			if(k==n){
				display(x);
				flag=1;
			}
			else{
				nQueen(k+1,n);
			}
		}
	}
}
int main(){
	printf("Enter the value of n : ");
	scanf("%d",&n);
	nQueen(1,n);
	if(flag==0){
		printf("\nNo Solution available !!");
	}
	return 0;
}
