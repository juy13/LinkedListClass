#pragma once


class ISorter
{
public:
	ISorter();
	~ISorter();
	template<typename TElement, template <typename ...> class Container>
	void bubleSort(Container<TElement> &array, int size);

	template<typename TElement, template <typename ...> class Container>
	void quickSort(Container<TElement> &arr, int left, int right);
};

template<typename TElement, template <typename ...> class Container>
void ISorter::bubleSort(Container<TElement> &array, int size)
{
	TElement tmp;
	int k;
	while (size > 1)
	{
		k = 0;
		for (int i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
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

template<typename TElement, template <typename ...> class Container>
void ISorter::quickSort(Container<TElement> &arr, int left, int right)
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