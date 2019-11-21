#pragma once


class ISorter
{
public:
	ISorter();
	~ISorter();
	template<typename TElement, template <typename ...> class Container, class Compare>
	void bubleSort(Container<TElement> &array, int size, Compare comp);

	template<typename TElement, template <typename ...> class Container, class Compare>
	void quickSort(Container<TElement> &arr, int left, int right, Compare comp);

	//template<typename TElement, template <typename ...> class Container, class Compare>
	//void shellSort(Container<TElement> &vector, int len, Compare comp);

	template<typename TElement, template <typename ...> class Container, class Compare>
	void  insert_sort(Container<TElement> &vector, int size, Compare comp);
};

template<typename TElement, template <typename ...> class Container, class Compare>
void ISorter::bubleSort(Container<TElement> &array, int size, Compare comp)
{
	//bool(*compare)(TElement, TElement) = func;
	TElement tmp;
	int k;
	while (size > 1)
	{
		k = 0;
		for (int i = 1; i < size; i++)
		{
			if (comp(array[i], array[i - 1]))
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				k = i;
			}
		}
		size = k;
	}
}

template<typename TElement, template <typename ...> class Container, class Compare>
void ISorter::quickSort(Container<TElement> &arr, int left, int right, Compare comp)
{
	int i = left, j = right;
	TElement tmp;
	TElement pivot = arr[(left + right) / 2];

	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;

		while (arr[j] > pivot)
			j--;

		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		this->quickSort(arr, left, j);

	if (i < right)
		this->quickSort(arr, i, right);

}

//template<typename TElement, template <typename ...> class Container, class Compare>
//void  ISorter::shellSort(Container<TElement> &vector, int len, Compare comp)
//{
//	int step = len / 2;
//	while (step > 0)
//	{
//		int i, j;
//		for (i = step; i < len; i++)
//		{
//			TElement value = vector[i];
//			for (j = i - step; (j >= 0) && (vector[j] > value); j -= step)
//				vector[j + step] = vector[j];
//			vector[j + step] = value;
//		}
//		step /= 2;
//	}
//}

template<typename TElement, template <typename ...> class Container, class Compare>
void  ISorter::insert_sort(Container<TElement> &vector, int size, Compare comp)
{
	for (int i = 1; i < size; i++)
	{
		TElement cur = vector[i];
		int j = i;
		while (j > 0 && cur < vector[j - 1])
		{
			vector[j] = vector[j - 1];
			j--;
		}
		vector[j] = cur;
	}
}


//void quickSort(int arr[], int left, int right) 
//{
//
//	int i = left, j = right;
//	int tmp;
//	int pivot = arr[(left + right) / 2];
//	   
//	/* partition */
//	while (i <= j) 
//	{
//		while (arr[i] < pivot)
//			i++;
//
//		while (arr[j] > pivot)
//			j--;
//
//		if (i <= j)
//		{
//			tmp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = tmp;
//			i++;
//			j--;
//		}
//	}
//
//	/* recursion */
//	if (left < j)
//		quickSort(arr, left, j);
//
//	if (i < right)
//		quickSort(arr, i, right);
//
//}