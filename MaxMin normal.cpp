#include<stdio.h>
void MaxMin(int arr[],int n){
	int max=arr[0];
	int min=arr[0];
	for(int i=1;i<n;i++){
		if(max<arr[i]){
			max=arr[i];
		}
		if(min>arr[i]){
			min=arr[i];
		}
	}
	printf("Max : %3d\tMin : %3d",max,min);
}
int main(){
	int arr2[5]={01,20,90,40,50};
	MaxMin(arr2,5);
}

