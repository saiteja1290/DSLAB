#include<stdio.h>
void main(){
	int a[100],n,i,t,count;
	printf("Enter lenght of array >>");
	scanf("%d",&n);
	printf("Enter array elements <100  >>");
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	printf("enter target element >>");
	scanf("%d",&t);
	count = 0;
	for(i=0;i<n;i++){
		if(a[i] == t){
			printf("element found at %d",i);
			count = count + 1;
		}
	}
	if(count == 0){
		printf("Element not found");
	}
}

