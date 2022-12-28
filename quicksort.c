#include<stdio.h>
int partition(int arr[] , int s , int e){
    int pivot = arr[s];
    int count = 0;

    for (int i = s+1; i <= e; i++){
        if(arr[i] <= pivot){
            count ++;
        }
    }
    
    int pivotindex = s + count;

    // swap pivot 
    int temp;
    temp = arr[pivotindex];
    arr[pivotindex] = arr[s];
    arr[s] = temp;


    int i = s;
    int j = e;

    while(i<pivotindex && j>pivotindex){
        while (arr[i] < pivot){
            i++;
        }
        while(arr[j] >= pivot){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
void quicksort(int arr[] , int s , int e){
    // base case:
    if(s >= e){
        return;
    }

    int p = partition(arr , s , e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
void main(){
    int arr[] = {5,4,3,2,1};
    int n = 5;
    quicksort(arr , 0 , n-1);
    for (int i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }
    
}
