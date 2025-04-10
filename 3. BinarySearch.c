#include<stdio.h>
int binarySearch(int arr[],int low,int high,int item){
	if(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==item){
			return mid;
		}
		else if(arr[mid]>item){
			return binarySearch(arr,low,mid-1,item);
		}
		else{
			return binarySearch(arr,mid+1,high,item);
		}
	}
	else{
		return -1;
	}
}
void display(int *arr,int n){
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
int main(){
	int n,x,result;
	printf("Enter the total number of elements : ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the array elements in sorted order : ");
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
	}
	printf("\nEnter the element to be searched : ");
	scanf("%d",&x);
	printf("\nThe Array elements are : ");
	display(arr,n);
	result=binarySearch(arr,0,n-1,x);
	if(result!=-1){
		printf("%d is present at index number : %d",x,result);
	}
	else{
		printf("%d is not present in the array",x);
	}
}
