#include <iostream>
using namespace std;

int city[10001] = { 0, };

int main()
{
	int n, m, sum = 0, ans = 0;
	int l=0, r = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> city[i];
		sum += city[i];
		if (city[i] > r)
			r = city[i];
	}
	cin >> m;


	while (l <= r)
	{
		int mid = (l + r) / 2;
		int money = 0;
		for (int i = 0;i < n;i++)
		{
			if (city[i] > mid)
				money += mid;
			else
				money += city[i];
		}

		if (m - money > 0)
		{
			ans = mid;
			l = mid + 1;
		}
		else if (m - money < 0)
			r = mid - 1;
		else
		{
			cout << mid;
			return 0;
		}
		
	}
	cout << ans;
}