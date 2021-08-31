#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INT_MAX 0x7fffffff

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int tc = 0;tc < testCase;tc++)
	{
		vector<pair<int,int>> v[10001];
		priority_queue<pair<int, int>> pq;
		int time[10001];
	
		int n,d,c,a,b,s;
		cin >> n >> d >> c;

		for (int j = 1;j <= n;j++)
		{
			time[j] = INT_MAX;
		}

		for (int j = 0;j < d;j++)
		{
			cin >> a >> b >> s;
			v[b].push_back({ s,a });
		}

		pq.push({ 0,c });
		time[c] = 0;
		int ans1 = 0,ans2=0;
		while (!pq.empty())
		{
			pair<int,int> tmp = pq.top();
			pq.pop();
			int cost = -tmp.first;
			int com = tmp.second;

			if (time[com] < cost)
				continue;

			for (int i = 0;i < v[com].size();i++)
			{
				if (time[v[com][i].second] > v[com][i].first + cost)
				{
					time[v[com][i].second] = v[com][i].first + cost;
					pq.push({ -time[v[com][i].second] ,v[com][i].second });
				}
			}
		}
		
		for (int i = 1;i <= n;i++)
		{
			if (time[i] != INT_MAX)
			{
				if (ans2 < time[i])
					ans2 = time[i];
				ans1 += 1;
			}
		}
		cout << ans1 << " " << ans2 << "\n";

	}
}