#include <iostream>
using namespace std;

int map[301][301];
int n, m;
int tmp[301][301];

void bfs(pair<int,int> start)
{
	
}


void iceBreak()
{
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,-1,1 };
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			tmp[i][j] = 0;
		}
	}

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (map[i][j] != 0)
			{
				int cnt = 0;
				for (int k = 0;k < 4;k++)
				{
					int x = j + dx[k];
					int y = i + dy[k];

					if (map[y][x] == 0)
						cnt++;
				}
				tmp[i][j] -= cnt;
			}
		}
	}

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			map[i][j] = tmp[i][j];
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
			cin>>map[i][j];
	}

	// 얼음 녹이기 -> +1 년
	// bfs or dfs  -> 분리되었는지 탐색하기




}