// 점프
// 시작점 1 점프해서 자기값 누적 0인경우 pass

#include <iostream>
using namespace std;

long long ans[101][101];
int map[101][101];

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cin >> map[i][j];
		}
	}
	ans[1][1] = 1;

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (ans[i][j] == 0)
				continue;
			if (i == j && i == n)
				break;
			if (j + map[i][j] <= n)
				ans[i][j + map[i][j]] += ans[i][j];
			if (i + map[i][j] <= n)
				ans[i + map[i][j]][j] += ans[i][j];
		}
	}
	cout << ans[n][n];
}