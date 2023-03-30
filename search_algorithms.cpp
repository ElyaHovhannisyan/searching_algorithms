#include "searching.h"

int main() {
	int	*array;
	
	array = make_arr();
	time_count(array);
	return 0;
}

int	linear_search(int *arr, int size, int element)
{
	int	i;

	for (i = 0; i < size; ++i)
		if(arr[i] == element)
			return (i);
	return (-1);
}

int	binary_search(int *arr, int size, int element)
{
	int begin = 0;
	int end = size;
	int mid;
	int i;
	
	while (begin <=  end)
	{
		mid = (begin + end) / 2;
	        if (arr[mid] == element)
	       		return (mid);
	 	if (element < arr[mid])
			end = mid - 1;
		else 
			begin = mid + 1;
	}
	return (-1);	
}

int	jump_search(int *arr, int size, int element)
{
	int	jump;
	int	i;
	int	j;

	i = 0;
	jump = sqrt(size);
	while (i < size)
	{
		if (arr[i] == element)
			return (i);
		if (arr[i] < element)
			i += jump;  
		else 
		{
			for (j = i - jump + 1; j < i; ++j)
				if (arr[j] == element)
					return (j);
			return (-1);
		}
	}
	return (-1);
}

int	*make_arr()
{
	int	*array;
	int	i;

	array = new int [90000000];
	for (i = 0; i < 90000000; ++i)
		array[i] = i;
	return (array);
}

void	time_count(int	*array)
{
	auto start = high_resolution_clock::now();
	int a = binary_search(array, 90000000, 10);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "Time taken by function binary_search: " << duration.count() << " microseconds\n";
	start = high_resolution_clock::now();
	a = jump_search(array,90000000,10);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << "Time taken by function jump_search: " << duration.count() << " microseconds\n";	
}