#include <iostream>
#include <cmath>
using namespace std;

int sosu[1001] = { 0, };

int main()
{
	sosu[1] = 1;

	int n;
	cin >> n;
	for (int i = 2;i <sqrt(1000)+1 ;i++)
	{
		if (sosu[i] == 0)
		{
			int idx = i * i;
			while (idx <= 1000)
			{
				sosu[idx] = 1;
				idx += i;
			}
		}
	}
	int ans = 0;
	for (int i = 0;i < n;i++)
	{
		int num;
		cin >> num;
		if (sosu[num] == 0)
			ans += 1;

	}
	cout << ans;
	return 0;
}