#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[10001];
vector<int> cnt[10001];
int maxIdx;

void bfs(int start)
{
	int cc = 0;
	int visit[10001] = { 0, };
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		for (int i = 0;i < v[s].size();i++)
		{
			if (!visit[v[s][i]])
			{
				visit[v[s][i]] = 1;
				q.push(v[s][i]);
				cc++;
			}
		}
	}
	cnt[cc].push_back(start);
}

int main()
{
	int b,c,d;
	cin >> maxIdx >> b;
	for (int i = 0;i < b;i++)
	{
		cin >> d >> c;
		v[c].push_back(d);
	}
	for (int i = 1;i <= maxIdx;i++)
	{
		bfs(i);
	}

	for (int i = maxIdx;i > 0;i--)
	{
		if (!cnt[i].empty())
		{
			for (int j = 0;j < cnt[i].size();j++)
			{
				cout << cnt[i][j] << " ";
			}
			break;
		}

	}
}
