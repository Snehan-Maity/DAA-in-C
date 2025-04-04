//Quick Sort
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void display(int arr[],int low,int high){
	int i;
	for(i=low;i<=high;i++){
		printf("%3d",arr[i]);
	}
}
int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low-1,j;
    printf("\nSubarray : ");
    display(arr,low,high);
    for(j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quickSort(int arr[], int low, int high){
    int j=low;
    if(low<high){
        j=partition(arr, low, high);
        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }
}
int main(){
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(i=0;i<n;i++)scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    printf("\nThe Sorted Array is: ");
    display(arr,0,n-1);
    return 0;
}
