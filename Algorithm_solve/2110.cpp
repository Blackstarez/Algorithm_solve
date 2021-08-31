#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> house;

int main()
{
	int n, c,ans = 0;
	long long l=0, r = 0,mid;
	cin >> n >> c;
	for (int i = 0;i < n;i++)
	{
		int num;
		cin >> num;
		house.push_back(num);
		if (r < num)
			r = num;
	}


	sort(house.begin(), house.end());


	while (l <= r)
	{
		mid = (l + r) / 2;
		int before = house[0];
		int m = c - 1;
		for (int i = 1;i < n;i++)
		{
			if (m <= 0)
				break;
			if (house[i] >= before + mid)
			{
				before = house[i];
				m-=1;
			}
		}

		if (m <= 0)
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	cout << ans;
}