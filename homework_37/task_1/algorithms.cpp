#include <iostream>

template <typename T>
void	swap(T *elem_1, T* elem_2)
{
	T	temp;

	temp = *elem_1;
	*elem_1 = *elem_2;
	*elem_2 = temp;
}

template <typename T>
void	bubble_sort(T *arr, std::size_t size)
{
	std::size_t	i;
	std::size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] < arr[j])
				swap(&arr[i], &arr[j]);
			++j;
		}
		++i;
	}
}

template <typename T>
void	merge(T *arr, std::size_t length, T *left, T *right)
{
	std::size_t	i;
	std::size_t	j;
	std::size_t	ind;
	std::size_t	mid;

	mid = length / 2;
	ind = 0;
	j = 0;
	i = 0;

	while (i < mid && j < length - mid)
	{
		if (left[i] < right[j])
			arr[ind++] = left[i++];
		else
			arr[ind++] = right[j++];
	}

	while (i < mid)
		arr[ind++] = left[i++];

	while (j < length - mid)
		arr[ind++] = right[j++];
}

template <typename T>
void	merge_sort(T *arr, std::size_t length)
{
	T			*left;
	T			*right;
	std::size_t	r_ind;
	std::size_t	mid;

	if (length <= 1)
		return ;

	r_ind = 0;
	mid	= length / 2;
	left = new T[mid];
	right = new T[length - mid];

	for (std::size_t i = 0; i < mid; ++i)
		left[i] = arr[i];

	for (std::size_t j = mid; j < length; ++j)
		right[r_ind++] = arr[j];

	merge_sort(left, mid);
	merge_sort(right, length - mid);
	merge(arr, length, left, right);

	delete[] left;
	delete[] right;
}

template <typename T>
std::size_t	partition(T *arr, std::size_t length)
{
	std::size_t	j;
	std::size_t	ind;
	T			pivot;

	ind = length - 1;
	pivot = arr[ind];
	j = 0;

	for (std::size_t i = 0; i < ind; ++i)
	{
		if (arr[i] < pivot)
		{
			swap(&arr[i], &arr[j]);
			++j;
		}
	}
	swap(&arr[j], &arr[ind]);
	return (j);
}

template <typename T>
void	quick_sort(T *arr, std::size_t length)
{
	std::size_t	pivot;

	if (length <= 1)
		return ;

	pivot = partition(arr, length);
	quick_sort(arr, pivot);
	quick_sort(arr + pivot + 1, length - pivot - 1);
}

int	main()
{
	/*int arr*/
	int	arr1[] = {5, 2, 7, 1, 5, 6, 9};
	std::size_t	size1 = sizeof(arr1) / sizeof(arr1[0]);
	merge_sort(arr1, size1);
	for (std::size_t i = 0; i < size1; ++i)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;

	/*double arr*/
	double	arr2[] = {5.5, 2.2, 9.9, 1.1, 5.5, 6.6};
	std::size_t	size2 = sizeof(arr2) / sizeof(arr2[0]);
	bubble_sort(arr2, size2);
	for (std::size_t i = 0; i < size2; ++i)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	/*double arr*/
	double	arr3[] = {5.5, 2.2, 9.9, 1.1, 5.5, 6.6};
	std::size_t	size3 = sizeof(arr3) / sizeof(arr3[0]);
	quick_sort(arr3, size3);
	for (std::size_t i = 0; i < size3; ++i)
		std::cout << arr3[i] << " ";
	std::cout << std::endl;

	return 0;
}
