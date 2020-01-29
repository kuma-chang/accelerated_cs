#include <stdio.h> 
#include <stdlib.h>

int arr[10000000];


void merge(int arr[], int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int L[n1], R[n2];
	
	int i = 0;
	int j = 0;//for the while loop to merge
	int k = left;//counter for the merged array


	//copying the two temp array prepare to be merge
	for(int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for(int j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j];

	while(i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
 
void merge_sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left)/2;

		merge_sort(arr, left, middle);
		merge_sort(arr, middle + 1, right);

		merge(arr, left, middle, right);
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


	merge_sort(arr, 0, arr_size - 1);



	//printing out the array after being sort
	printf("\n\n[After] \n");
	for(int i = 0; i < arr_size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
