#include<stdio.h>
void main(){
	int a[100],n,i,t,count;
	printf("Enter lenght of array >>");
	scanf("%d",&n);
	printf("Enter sorted array elements <100  >>");
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	printf("enter target element >>");
	scanf("%d",&t);
	int x = 0;
	int y = n-1;
	int mid = (x + y)/2;
	while( t!=a[mid]){
		if(t>a[mid]){
			x = mid;
			mid = (x+y)/2;
		}
		else{
			y = mid;
			mid = (x+y)/2;
		}
	}
	printf("Element found at %d",mid);
}

