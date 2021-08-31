#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[101];
int maxNum;
int find1, find2;

int main()
{
	cin >> maxNum;
	cin >> find1 >> find2;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int visit[101] = { 0, };

	queue<pair<int, int>> q;
	q.push({ find1,0 });
	while (!q.empty())
	{
		pair<int,int> k = q.front();
		q.pop();
		int x = k.first, value = k.second;
		for (int i = 0;i < v[x].size();i++)
		{
			if (find2 == v[x][i])
			{
				cout << value+1;
				return 0;
			}
			if (!visit[v[x][i]])
			{
				visit[v[x][i]] = 1;
				q.push({ v[x][i], value + 1 });
			}
		}
	}
	cout << -1;
	return 0;
}