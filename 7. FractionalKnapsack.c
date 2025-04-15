#include<stdio.h>
#include<stdlib.h>
struct item{
	int profit,weight;
	int ppw;
};
void bubble(struct item list[],int n){
	int i,j;
	struct item temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(list[j].ppw<list[j+1].ppw){
				temp=list[j];
				list[j]=list[j+1];
				list[j+1]=temp;
			}
		}
	}
}
void FractionalKnapsack(struct item list[],int n,float m){
	bubble(list,n);
	double x[n];
	int i;
	for(i=0;i<n;i++){
		x[i]=0.0;
	}
	float u=m;
	for(i=0;i<n;i++){
		if(list[i].weight>u){
			break;
		}
		x[i]=1.0;
		u=u-list[i].weight;
	}
	if(i<n){
		x[i]=u/list[i].weight;
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%f\t",x[i]);
	}
}
int main(){
	int n,i;
	float m;
	printf("Enter the number of items : ");
	scanf("%d",&n);
	printf("Enter the Knapsack capacity : ");
	scanf("%f",&m);
	struct item list[n];
	printf("Enter the profit and weight of the items : ");
	for(i=0;i<n;i++){
		scanf("%d %d",&list[i].profit,&list[i].weight);
		
	}
	for(i=0;i<n;i++){
		list[i].ppw=list[i].profit/list[i].weight;
	}
	FractionalKnapsack(list,n,m);
	return 0;
}
