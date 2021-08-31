#include <iostream>
using namespace std;

int lan[10001] = { 0, };

int main()
{
	int a, b,ans = 1;
	long long l = 0, r = 0;
	cin >> a >> b;
	for (int i = 0;i < a;i++)
	{
		cin >> lan[i];
		if (lan[i] > r)
			r = lan[i];
	}

	while (l <= r)
	{
		long long mid = (l + r) / 2;
		int cnt = b;

		for (int i = 0;i < a;i++)
		{
			if (cnt <= 0)
				break;
			if (mid <= 0)
				break;
			cnt -= (lan[i] / mid);
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