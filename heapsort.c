

#include <stdio.h>

int i,j,k;
void swap(int* a, int* b)
{

	int temp = *a;

	*a = *b;

	*b = temp;
}

void heapify(int arr[], int N, int i)
{
	
	int largest = i;

	
	int left = 2 * i + 1;

	
	int right = 2 * i + 2;


	if (left < N && arr[left] > arr[largest])

		largest = left;

	
	if (right < N && arr[right] > arr[largest])

		largest = right;


	if (largest != i) {

		swap(&arr[i], &arr[largest]);


		heapify(arr, N, largest);
	}
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

	// Build max heap
	for (i = N / 2 - 1; i >= 0; i--)

		heapify(arr, N, i);

	// Heap sort
	for (i = N - 1; i >= 0; i--) {

		swap(&arr[0], &arr[i]);

		// Heapify root element to get highest element at
		// root again
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
	for ( i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver's code
int main()
{
	int arr[100],n;
	printf("Enter the size of the array >>");
	scanf("%d",&n);
	for(i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
//	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr, n);
	printf("Sorted array is\n");
	printArray(arr, n);
}

// This code is contributed by _i_plus_plus_.
