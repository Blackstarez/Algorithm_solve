#include <iostream>
#include <queue>
#include <vector>
#define INT_MAX 0x7fffffff
using namespace std;

vector<pair<int,int>> p[1001];
int weight[1001];
priority_queue<pair<int, int>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0;i < 1001;i++)
		weight[i] = INT_MAX;


	int city, bus;
	cin >> city >> bus;
	for (int i = 0;i < bus;i++)
	{
		int s, d, w;
		cin >> s >> d >> w;
		p[s].push_back({ w,d });
	}
	int start, end;
	cin >> start >> end;

	pq.push({ 0,start });
	weight[start] = 0;

	while (!pq.empty())
	{
		pair<int, int> tmp = pq.top();
		pq.pop();
		int cost = tmp.first;
		int curCity = tmp.second;

		if (cost > weight[curCity])
			continue;

		for (int i = 0;i < p[curCity].size();i++)
		{
			if (weight[p[curCity][i].second] > p[curCity][i].first + cost)
			{
				weight[p[curCity][i].second] = p[curCity][i].first + cost;
				pq.push({ weight[p[curCity][i].second],p[curCity][i].second });
			}
		}

	}
	cout << weight[end];
}