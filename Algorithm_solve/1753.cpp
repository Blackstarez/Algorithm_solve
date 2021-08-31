#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INT_MAX 0x7fffffff

int weight[20001] = { INT_MAX, };
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> k[20001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0;i < 20001;i++)
		weight[i] = INT_MAX;


	int v, e;
	cin >> v >> e;
	int start;
	cin >> start;
	for (int i = 0;i < e;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		k[a].push_back({ b,c });
	}
	weight[start] = 0;

	pq.push({ 0,start });

	while (!pq.empty())
	{
		pair<int, int> tmp = pq.top();
		tmp.first *= -1;
		pq.pop();

		if (weight[tmp.second] < tmp.first)
			continue;
		for (int i = 0;i < k[tmp.second].size();i++)
		{
			// tmp 가 가장 값이 작은것 
			if (weight[k[tmp.second][i].first] > tmp.first + k[tmp.second][i].second)
			{
				weight[k[tmp.second][i].first] = tmp.first + k[tmp.second][i].second;
				pq.push({ -weight[k[tmp.second][i].first],k[tmp.second][i].first });
			}

		}
		
	}
	for (int i = 1;i <= v;i++)
	{
		if (weight[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << weight[i] << "\n";
	}

}