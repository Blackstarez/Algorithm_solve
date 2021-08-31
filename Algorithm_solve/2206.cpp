#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int visit[1001][1001] = { {0,}, };
int visitc[1001][1001] = { {0,}, };
int n, m;

int main()
{
	cin >> n >> m;
	cin.get();
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			char c = cin.get();
			if (c == '0')
				map[j][i] = 0;
			else if (c == '1')
				map[j][i] = 1;
		}
		cin.get();
	}

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{1,1} });
	visit[0][0] = 1;

	while (!q.empty())
	{
		int chance, x, y, move;
		pair<pair<int, int>, pair<int, int>> p = q.front();
		q.pop();
		x = p.first.first; y = p.first.second;
		move = p.second.first; chance = p.second.second;

		for (int i = 0;i < 4;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx <n && ny < m)
			{
				if (chance)
				{
					if (!map[ny][nx])
					{
						if (visitc[ny][nx] == 0 || visitc[ny][nx] > move + 1)
						{
							q.push({ {nx,ny},{move + 1,chance} });
							visitc[ny][nx] = move + 1;
						}
					}
					else
					{ 
						if (visit[ny][nx] == 0 || visit[ny][nx] > move + 1)
						{
							q.push({ {nx,ny},{move + 1,0} });
							visit[ny][nx] = move + 1;
						}
					}
				}
				else
				{
					if (map[ny][nx] == 0 )
					{
						if (visit[ny][nx] == 0 || visit[ny][nx] > move + 1)
						{
							q.push({ {nx,ny},{move + 1,0} });
							visit[ny][nx] = move + 1;
						}
					}
				}
			}
		}
	}

	if (visit[m - 1][n - 1]!= 0 && visitc[m-1][n-1] != 0)
	{
		cout << min(visit[m - 1][n - 1], visitc[m - 1][n - 1]);
	}
	else if (visit[m - 1][n - 1] != 0 && visitc[m - 1][n - 1] == 0)
	{
		cout << visit[m - 1][n - 1];
	}
	else if (visit[m - 1][n - 1] == 0 && visitc[m - 1][n - 1] != 0)
	{
		cout << visitc[m - 1][n - 1];
	}
	else
		cout << -1;
	return 0;
}