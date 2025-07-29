//Merge Sort
#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int low,int mid,int high){
	int i=low;
	int j=mid+1;
	int k=0;
	int temp[high-low+1];
	while(i<=mid && j<=high){
		if(arr[i]<=arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid){
		temp[k++]=arr[i++];
	}
	while(j<=high){
		temp[k++]=arr[j++];
	}
	k=0;
	for(i=low;i<=high;i++){
		arr[i]=temp[k++];
	}
}
void mergeSort(int arr[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
void display(int arr[],int low,int high){
	int i;
	for(i=low;i<=high;i++){
		printf("%3d",arr[i]);
	}
}
int main(){
	int n,i;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	int *arr=(int *)malloc(n*sizeof(int));
	printf("Enter the elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\nThe original array is : ");
	display(arr,0,n-1);
	mergeSort(arr,0,n-1);
	printf("\nThe sorted array is : ");
	display(arr,0,n-1);
	return 0;
}
