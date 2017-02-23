// 42 header

 // sorts in place aka in memory if you want a coppy of the original better save it prior to running this

static void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *arr, int left, int right)
{
	int pivot;

	pivot = arr[left];
	while (left < right)
	{
		while (arr[left] <= pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left < right)
			swap(&arr[left], &arr[right]);
	}
	swap(&arr[pivot], &arr[right]);
	return (right);
}

void		quicksort(int *arr, int start, int end)
{
	int	pivot;

	pivot = 0;
	if (start < end)
	{
		pivot = partition(arr, start, end);
		quicksort(arr, start, pivot - 1);
		quicksort(arr, pivot + 1, end);
	}
	else
		return ;
}