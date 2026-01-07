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
void	merge(T *arr, std::size_t left, std::size_t mid, std::size_t right)
{
	T			*tmp1;
	T			*tmp2;
	std::size_t	ind;
	std::size_t	l_ind;
	std::size_t	r_ind;

	tmp1 = new T[mid - left + 1];
	tmp2 = new T[right - mid];

	for (std::size_t i = 0; i < mid; i++)
		tmp1[i] = arr[i];

	for (std::size_t i = 0; i < right - mid; ++i)
		tmp2[i] = arr[mid + i + 1];

	ind = left;
	l_ind = 0;
	r_ind = 0;

	while (l_ind < (mid - left + 1) && r_ind < (right - ind))
	{
		if (tmp1[l_ind] < tmp2[r_ind])
		{
			arr[ind] = tmp1[l_ind];
			++l_ind;
			++ind;
		}
		else
		{
			arr[ind] = tmp2[r_ind];
			++r_ind;
			++ind;
		}
	}

	while (l_ind < (mid - left + 1))
	{
		arr[ind] = tmp1[l_ind];
		++l_ind;
		++ind;
	}

	while (r_ind < (right - mid))
	{
		arr[ind] = tmp2[r_ind];
		++r_ind;
		++ind;
	}
	
	delete[] tmp1;
	delete[] tmp2;
}

template <typename T>
void	merge_sort(T *arr, std::size_t left, std::size_t right)
{
	std::size_t	mid;

	if (left >= right)
		return ;
	mid = left + (right - left) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}


int	main()
{
	/*int arr*/
	/*
	*/
	int	arr[] = {5, 2, 9, 1, 5, 6};
	std::size_t	size = sizeof(arr) / sizeof(arr[0]);
	merge_sort(arr, 0, size - 1);
	for (std::size_t i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	/*double arr*/
	/*
		double	arr[] = {5.5, 2.2, 9.9, 1.1, 5.5, 6.6};
		std::size_t	size = sizeof(arr) / sizeof(arr[0]);
		bubble_sort(arr, size);
		for (std::size_t i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	*/

	return 0;
}
