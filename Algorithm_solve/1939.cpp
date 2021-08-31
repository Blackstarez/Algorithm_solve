#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> bridge[10001];
int n;
int visit[10001] = { 0, };


bool dfs(int start, int end,int maxCost)
{

	if (start == end)
	{
		return true;
	}

	for (int i = 0;i < bridge[start].size();i++)
	{
		if (bridge[start][i].second >= maxCost && !visit[bridge[start][i].first])
		{
			visit[bridge[start][i].first] = 1;
			bool flag = dfs(bridge[start][i].first, end, maxCost);
			if (flag)
				return true;
			
		}
	}
	return false;
}


int main()
{
	int  m,ans = 0;
	int l = 1, r = 1;
	cin >> n >> m;
	for (int i = 0;i < m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		bridge[a].push_back({ b,c });
		bridge[b].push_back({ a,c });
		if (c > r)
			r = c;
	}
	int start, end;
	cin >> start >> end;

	while (l <= r)
	{
		int mid = (l + r) / 2;
		bool flag = false;
		flag = dfs(start, end, mid);
		if (flag)
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;

		for (int i = 0;i <= n;i++)
			visit[i] = 0;

	}
	cout << ans;
	return 0;
}