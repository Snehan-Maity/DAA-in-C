//MaxMin
#include<stdio.h>
#include<stdlib.h>
int c=0;
void MaxMin(int arr[],int i,int j,int *max,int *min){
	int max2=INT_MIN;
	int min2=INT_MAX;
	if(i==j){
		*max=arr[i];
		*min=arr[j];	
	}
	else if(i==j-1){
		c++;
		if(arr[i]<arr[j]){
			*max=arr[j];
			*min=arr[i];
		}
		else{
			*max=arr[i];
			*min=arr[j];	
		}
	}
	else{
		int mid=(i+j)/2;
		MaxMin(arr,i,mid,max,min);
		MaxMin(arr,mid+1,j,&max2,&min2);
		if(c++ && *max<max2){
			*max=max2;
		}
		if(c++ && *min>min2){
			*min=min2;
		}
	}
}
int main(){
	int i,n;
	int max=INT_MIN,min=INT_MAX;
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	MaxMin(arr,0,n-1,&max,&min);
	printf("Maximum : %3d\nMinimum : %3d",max,min);
	printf("\nTotal number of comparisons required : %3d",c);
}
