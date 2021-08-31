#include <iostream>
using namespace std;

int su[10002];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
		cin >> su[i];
	su[n] = 0;

	int l = -1, r = -1;
	int curNum = 0,ans = 0;
	while (l < n)
	{
		if (curNum <= m)
		{
			curNum += su[++r];
		}
		else
		{
			curNum -= su[++l];
		}
		if (su[r] != 0 && curNum == m)
			ans++;
	}
	cout << ans;

}