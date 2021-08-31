#include <iostream>
#include <queue>
#include<vector>
using namespace std;

vector<int> v[100001];
int parent[100001];
int maxSize;

int main()
{

	cin >> maxSize;
	for (int i = 0;i < maxSize-1;i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	int visit[100001] = { 0, };
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0;i < v[x].size();i++)
		{
			if (!visit[v[x][i]])
			{
				visit[v[x][i]] = 1;
				q.push(v[x][i]);
				parent[v[x][i]] = x;
			}
		}
	}

	for (int i = 2;i <= maxSize;i++)
	{
		cout << parent[i] << "\n";
	}

}