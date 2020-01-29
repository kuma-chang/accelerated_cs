#include <stdio.h> 
#include <stdlib.h>

int arr[10000000];


void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition(int arr[], int low, int high)
{
	int start = arr[high];
	int i = (low - 1);

	for(int j = low; j <= high - 1; j++)
	{
		if(arr[j] < start)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void special_partition_sort(int arr[], int low, int high)
{
	if(low < high)
	{
		int index = partition(arr, low, high);

		special_partition_sort(arr, low, index - 1);
		special_partition_sort(arr, index + 1, high);
	}
}





int main()
{
	//getting the array size
	int arr_size;
	scanf("%d", &arr_size);
	printf("SIZE: %d\n", arr_size);

	//getting each element of the array
	for(int i = 0; i < arr_size; i++)
	{
		scanf("%d", &arr[i]);
	}

	//printing out the array before being sort
	printf("[Before] \n");
	for(int i = 0; i < arr_size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");


	special_partition_sort(arr, 0, arr_size - 1);



	//printing out the array after being sort
	printf("\n\n[After] \n");
	for(int i = 0; i < arr_size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
