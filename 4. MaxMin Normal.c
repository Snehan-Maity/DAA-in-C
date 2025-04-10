#include<stdio.h>
int c=0;
void MaxMin(int arr[],int n){
	int max=arr[0];
	int min=arr[0];
	for(int i=1;i<n;i++){
		if(max<arr[i]){
			max=arr[i];
			c++;
		}
		if(min>arr[i]){
			min=arr[i];
			c++;
		}
	}
	printf("Max : %3d\tMin : %3d",max,min);
	printf("\nTotal number of comparisons : %d",c);
}
int main(){
	int i,n;
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	MaxMin(arr,n);
}
