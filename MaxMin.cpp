#include<stdio.h>
#include<stdlib.h>
int c=0;
void MaxMin(int arr[],int i,int j,int *max,int *min){
	int max2=INT_MIN;
	int min2=INT_MAX;
	if(i==j){
		*max=arr[i];
		*min=arr[i];	
	}
	if(i==j-1){
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
		else if(c++ && *min>min2){
			*min=min2;
		}
	}
}
int main(){
	int arr2[5]={10,20,30,40,50};
	int max=INT_MIN,min=INT_MAX;
	MaxMin(arr2,0,4,&max,&min);
	printf("Maximum : %3d\nMinimum : %3d",max,min);
	printf("Total number of comparisons required : %3d",c);
}

