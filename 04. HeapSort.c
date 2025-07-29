//Heap Sort
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapAdjust(int arr[], int i, int n){
    int j=2*i;
    int key=arr[i];
    while(j<=n){
        if(j<n && arr[j]<arr[j+1]){
            j+=1;
    	}
        if(key>=arr[j]){
            break;
    	}
        arr[j/2]=arr[j];
        j=2*j;
    }
    arr[j/2]=key;
}
void makeHeap(int arr[], int n){
	int i;
    for(i=n/2;i>0;i--){
        heapAdjust(arr,i,n);
    }
}
void heapSort(int arr[], int n){
    makeHeap(arr,n);
    int i;
    for(i=n;i>1;i--){
        swap(&arr[i],&arr[1]);
        heapAdjust(arr,1,i-1);
    }
}
int main(){
    int n,i;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int *arr=(int *)malloc((n+1)*sizeof(int));
    printf("Enter the elements : ");
    for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}	
    heapSort(arr, n);
    printf("The Sorted Array is : ");
    for(i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
    return 0;
}
