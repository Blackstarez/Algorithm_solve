#include <iostream>
using namespace std;


int r =0;
int l = 0;
int money[100001] = { 0, };

int main()
{
	int n, m,ans = 0;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		int num;
		cin >> num;
		money[i] = num;
		if (l < num)
		{
			l = num;
		}
		r += num;
	}


	while (l <= r)
	{
		int mid = (l + r) / 2;
		// mid를 활용하여 test
		int cnt = 0,curMoney = 0;
		for (int i = 0;i < n;i++)
		{
			if (curMoney < money[i])
			{
				curMoney = mid;
				cnt++;
			}
			curMoney-= money[i];
		}

		if (cnt<=m)
		{
			r = mid - 1;
			ans = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << ans;
}
