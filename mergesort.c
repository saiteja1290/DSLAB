#include<stdio.h>
void merge(int arr[], int s , int e){
    int mid = (s+e)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int first[len1];
    int second[len2];

    //copying values:
    int k = s;
    for (int i = 0; i < len1; i++){
        first[i] = arr[k];
        k++;
    }
    // for (int i = 0; i < len1; i++)
    // {
    //     printf("%d\t",first[i]);
    // }
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k];
        k++;
    }

    k = s;
    int firstindex = 0;
    int secondindex = 0;
    while (firstindex < len1 && secondindex < len2)
    {
        if(first[firstindex] < second[secondindex]){
            arr[k] = first[firstindex];
            firstindex++;
            k++;
        }
        else{
            arr[k] = second[secondindex];
            secondindex++;
            k++;
        }
    }

    while (firstindex < len1)
    {
        arr[k] = first[firstindex];
        firstindex++;
        k++;
    }

    while(secondindex < len2){
        arr[k] = second[secondindex];
        secondindex++;
        k++;
    }
    
}
void mergesort(int arr[] , int s ,int e){
    if(s >= e){
        return;
    }
    int mid = (s+e)/2;
    mergesort(arr , s , mid);
    mergesort(arr,mid+1,e);

    merge(arr,s,e);
}
void main(){
    int arr[] = {5,4,3,2,1};
    int n = 5;
    mergesort(arr,0,n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    
}
