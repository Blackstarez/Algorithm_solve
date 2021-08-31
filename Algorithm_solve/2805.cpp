#include <iostream>
using namespace std;

int tree[1000001] = { 0, };

int main()
{
	int n, ans = 0, m;
	long long l = 0, r = 0;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> tree[i];
		if (r < tree[i])
			r = tree[i];
	}

	while (l <= r)
	{
		long long mid = (l + r) / 2;
		int  cnt = m;
		for (int i = 0;i < n;i++)
		{
			if (cnt <= 0)
				break;
			if (tree[i] > mid)
			{
				cnt -= (tree[i] - mid);
			}
		}
		
		if (cnt <= 0)
		{
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	cout << ans;
}