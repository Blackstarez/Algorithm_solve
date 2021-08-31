#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	queue<pair<int, int>> q;
	int visit[200001] = { 0, };
	q.push({ a,0 });
	visit[a] = 1;
	while (!q.empty())
	{
		pair<int, int> x = q.front();
		q.pop();
		if (x.first == b)
		{
			cout << x.second;
			return 0;
		}
		if (!visit[x.first + 1] && x.first < 100000 && x.first>=0)
		{
			visit[x.first + 1] = 1;
			q.push({ x.first + 1,x.second + 1 });
		}
		if (!visit[x.first - 1] && x.first < 100002 && x.first>0)
		{
			visit[x.first - 1] = 1;
			q.push({ x.first - 1,x.second + 1 });
		}
		if (!visit[x.first * 2] && x.first<50001 && x.first>=0)
		{
			visit[x.first * 2] = 1;
			q.push({ x.first * 2,x.second + 1 });
		}
	}
	return 0;
}