#include <iostream>
using namespace std;

int cnt[11] = { 0, };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0;i < 11;i++)
	{
		if (i - 3 >= 0)
		{
			cnt[i] = cnt[i - 2] + cnt[i - 1] + cnt[i - 3];
		}
		else if (i - 2 >= 0)
		{
			cnt[i] = cnt[i - 2] + cnt[i - 1];
		}
		else
			cnt[i] = 1;
	}

	int testCase, num;
	cin >> testCase;
	for (int i = 0;i < testCase;i++)
	{
		cin >> num;
		cout << cnt[num] << "\n";
	}
}