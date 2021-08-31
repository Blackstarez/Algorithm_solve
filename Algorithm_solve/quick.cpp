#include <iostream>
using namespace std;

void quickSort(int arr[],int l,int r)
{
	int	left = l;
	int right = r;
	int	pivot = arr[(l+r)/2];
	while (left < right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			int tmp = arr[left];
			arr[left++] = arr[right];
			arr[right--] = tmp;
		}
	}
	
	if (l < right)
		quickSort(arr, l, right);
	if (r > left)
		quickSort(arr, left, r);
}


int main()
{
	int a[10] = { 2,4,8,6,1,3,5,7,9,10 };
	quickSort(a, 0, 9);
	for (int i = 0;i < 10;i++)
		cout << a[i] << " ";

}