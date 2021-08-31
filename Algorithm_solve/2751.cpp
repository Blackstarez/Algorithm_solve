#include <iostream>
using namespace std;

void merge(int *arr, int left, int right)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;

	merge(arr, left, mid);
	merge(arr, mid + 1, right);
	
	int lIdx = left;
	int rIdx = mid + 1;
	

	int* tmp = new int[right - left + 1];
	int cnt = 0;

	while (lIdx <= mid && rIdx <= right)
	{
		if (arr[lIdx] <= arr[rIdx])
			tmp[cnt++] = arr[lIdx++];
		else
			tmp[cnt++] = arr[rIdx++];
	}

	while (lIdx <= mid)
		tmp[cnt++] = arr[lIdx++];

	while (rIdx <= right)
		tmp[cnt++] = arr[rIdx++];

	for (int i = 0;i < cnt;i++)
	{
		arr[left+i] = tmp[i];
	}
}


int main()
{
	int* a, n;
	cin >> n;
	a = new int[n];
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	merge(a, 0, n-1);

	for(int i = 0;i < n;i++)
		cout << a[i] << "\n";
}