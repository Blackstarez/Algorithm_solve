#include <iostream>
using namespace std;

long long ans = 0;
int tmp[500001], a[500001];

void merge(int p, int q, int r)
{
	int idx = p;
	int left = p, right = q+1;	// merge대상 좌측 배열과 우측배열 index
	int cnt = 0;
	while (left <= q || right <= r) {
		// 왼쪽것 끝났으면
		if (left > q) 
		{
			tmp[idx++] = a[right++];
			cnt++;
		}
		// 오른쪽것 끝났으면
		else if (right > r) 
		{
			tmp[idx++] = a[left++];
			ans += cnt;
		}
		// a[left]가 더 크거나 같으면
		else if (a[left] > a[right]) 
		{
			tmp[idx++] = a[right++];
			cnt++;
		}
		else
		{
			tmp[idx++] = a[left++];
			ans += cnt;
		}
	}
	// 원본배열로 옮기기
	for (int i = p;i <= r;i++)
	{
		a[i] = tmp[i];
	}
}

void mergeSort(int p, int r)
{
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(p, q);
		mergeSort(q + 1, r);
		merge(p, q, r);
	}
}

int main() {
	int length;
	cin >> length;
	for (int i = 0;i < length;i++) 
	{
		cin >> a[i];
	}

	mergeSort(0, length - 1);
	cout << ans;
}