#include <iostream>
using namespace std;

int cnt[1000001] = { 0, };

int main()
{
	int num;
	cin >> num;
	for (int i = 2;i <= num;i++)
	{
		if (i % 3 == 0 && i % 2 == 0)
		{
			cnt[i] = cnt[i - 1] > cnt[i / 2] ? (cnt[i / 2] > cnt[i / 3] ? cnt[i / 3] + 1 : cnt[i / 2] + 1) : (cnt[i - 1] > cnt[i / 3] ? cnt[i / 3] + 1 : cnt[i - 1] + 1);
		}
		else if (i % 3 != 0 && i % 2 == 0)
		{
			cnt[i] = min(cnt[i - 1], cnt[i / 2]) + 1;
		}
		else if (i % 3 == 0 && i % 2 != 0)
		{
			cnt[i] = min(cnt[i - 1], cnt[i / 3]) + 1;
		}
		else
		{
			cnt[i] = cnt[i - 1] + 1;
		}
		
	}
	cout << cnt[num];
}