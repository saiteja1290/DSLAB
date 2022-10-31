#include<stdio.h>
void main(){
	int a[100],n,i,j,count,t;
	printf("Enter lenght of array >>");
	scanf("%d",&n);
	printf("Enter array elements <100  >>");
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(a[j+1]<a[j]){
				t = a[j+1];
				a[j+1] = a[j];
				a[j] = t;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
}

