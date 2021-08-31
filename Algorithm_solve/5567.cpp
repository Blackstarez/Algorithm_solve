#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	vector<int> v[501];
	int n, m,a,b,ans=0;
	cin >> n >> m;
	for (int i = 0;i < m;i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int visit[501] = { 1,1,0, };
	queue<pair<int, int>> q;
	q.push({ 1,0 });
	while (!q.empty())
	{
		pair<int, int> x = q.front();
		q.pop();
		for (int i = 0;i < v[x.first].size();i++)
		{
			if (x.second < 2 && !visit[v[x.first][i]])
			{
				visit[v[x.first][i]] = 1;
				q.push({ v[x.first][i],x.second + 1 });
				ans++;
			}
		}
	}
	cout << ans;
}