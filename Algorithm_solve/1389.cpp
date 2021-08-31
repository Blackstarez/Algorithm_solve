#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MAX 0x7fffffff
using namespace std;

int user[101][101] = { 0, };
vector < pair<int, int>> v;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			user[i][j] = INT_MAX;
			if (i == j)
				user[i][j] = 0;
		}
	}
	for (int i = 0;i < m;i++)
	{
		int a, b;
		cin >> a >> b;
		user[a][b] = 1;
		user[b][a] = 1;
	}
	
	for (int k = 1;k <= n;k++)
	{
		for (int i = 1;i <= n;i++)
		{
			if (i == k)
				continue;
			for (int j = 1;j <= n;j++)
			{
				if (j == k || j == i)
					continue;
				if (user[i][k] == INT_MAX || user[k][j] == INT_MAX)
				{
					if (user[i][j] == INT_MAX)
						user[i][j] = INT_MAX;
				}
				else
					user[i][j] = min(user[i][k] + user[k][j], user[i][j]);
			}
		}
	}


	for (int i = 1;i <= n;i++)
	{
		int cnt = 0;
		for (int j = 1;j <= n;j++)
		{
			if(user[i][j] != INT_MAX)
				cnt += user[i][j];
		}
		v.push_back({ cnt,i });
	}

	sort(v.begin(), v.end());

	cout << v.front().second;
}