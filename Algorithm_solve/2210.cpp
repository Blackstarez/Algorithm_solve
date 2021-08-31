#include <iostream>
#include <set>
#include <string>
#include <cmath>
using namespace std;

int map[6][6];
set<int> a;

void dfs(int s,int x, int y, int depth)
{
	if (depth == 6)
	{
		a.insert(s);
		return;
	}
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx>5 || ny> 5)
			continue;
		dfs(s*10+map[ny][nx],nx, ny, depth + 1);
	}
}

int main()
{
	for (int i = 1;i <= 5;i++)
	{
		for (int j = 1;j < 6;j++)
		{
			cin >> map[j][i];
		}
	}
	
	for (int i = 1;i < 6;i++)
	{
		for (int j = 1;j < 6;j++)
		{
			dfs(map[i][j], j, i, 1);
		}
	}
	cout << a.size();
}
