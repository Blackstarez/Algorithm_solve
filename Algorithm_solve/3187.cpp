#include <iostream>
#include <queue>
using namespace std;

int r, c;
char map[251][251] = { {0,}, };
int visit[251][251] = { {0,}, };

pair<int,int> bfs(int x, int y)
{
	
	pair<int, int> kv = { 0 ,0};
	if (map[x][y] == 'k')
		kv.first += 1;
	else if (map[x][y] == 'v')
		kv.second += 1;
	queue < pair<int, int>> q;
	q.push({ x,y });

	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	while (!q.empty())
	{
		pair<int, int> tmp = q.front();
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			int nx = tmp.first + dx[i];
			int ny = tmp.second + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
				continue;
			if (!visit[nx][ny] && map[nx][ny] != '#')
			{
				visit[nx][ny] = 1;
				if (map[nx][ny] == 'v')
				{
					q.push({ nx,ny});
					kv.second += 1;					
				}
				else if (map[nx][ny] == 'k')
				{
					q.push({ nx,ny });
					kv.first += 1;						
				}
				else
					q.push({ nx,ny});
			}
		}
	}
	return kv;
}


int main()
{
	int k=0, v = 0;
	cin >> r >> c;
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			if (!visit[i][j] && map[i][j] != '#')
			{
				visit[i][j] = 1;
				pair<int,int> kv = bfs(i, j);
				if (kv.first > kv.second)
					k += kv.first;
				else
					v += kv.second;
			}
		}
	}

	cout << k << " " << v;
}