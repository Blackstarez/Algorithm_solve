#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[8];

void bfs(int start)
{
	cout << start << " : ";
	int visit[8] = { 0, };
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
				cout << v[s][i] << " ";
			}

		}
	}
	cout << endl;

}

int main()
{
	int a, b, c, d;
	cin >> a >> b;
	for (int i = 0;i < b;i++)
	{
		cin >> d >> c;
		v[d].push_back(c);
		v[c].push_back(d);
	}
	for (int i = 1;i <= a;i++)
	{
		bfs(i);
	}


}


/*

1/23/45/7/6
2145367
3172645
4261573
5261473
6457231
7361452

7 8
1 2
1 3
2 4
2 5
4 6
5 6
6 7
3 7


*/