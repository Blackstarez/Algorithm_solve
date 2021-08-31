#include <iostream>
#include <queue>
using namespace std;

char map[101][101] = { {0,}, };
int mapSize;
int visit1[101][101] = { {0,}, };
int visit2[101][101] = { {0,}, };

void bfs(int x,int y,bool isBlind)
{
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };
	queue<pair<int, int>> q;
	q.push({ x, y });
	char color = map[y][x];

	while (!q.empty())
	{
		pair<int, int>tmp = q.front();
		q.pop();
		x = tmp.first;
		y = tmp.second;

		for (int i = 0;i < 4;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > 0 && ny > 0 && nx <= mapSize && ny <= mapSize)
			{
				if (isBlind)
				{
					if (color == 'R' || color == 'G')
					{
						if (!visit2[ny][nx])
						{
							if (map[ny][nx] == 'R' || map[ny][nx] == 'G')
							{
								visit2[ny][nx] = 1;
								q.push({ nx,ny });
							}
						}
					}
					else
					{
						if (!visit2[ny][nx] && map[ny][nx] == 'B')
						{
							visit2[ny][nx] = 1;
							q.push({ nx,ny });
						}
					}
				}
				else
				{
					if (!visit1[ny][nx] && map[ny][nx] == color)
					{
						visit1[ny][nx] = 1;
						q.push({ nx,ny });
					}
				}
			}

		}
	}
	


}

int main()
{
	cin >> mapSize;
	for (int i = 1;i <= mapSize;i++)
	{
		for (int j = 1;j <= mapSize;j++)
		{
			cin >> map[j][i];
		}
	}


	int ans1=0, ans2=0;
	
	for (int i = 1;i <= mapSize;i++)
	{
		for (int j = 1;j <= mapSize;j++)
		{
			if (!visit1[j][i])
			{
				visit1[j][i] = 1;
				bfs(i, j, false);
				ans1++;
			}
			if (!visit2[j][i])
			{
				visit2[j][i] = 1;
				bfs(i, j, true);
				ans2++;
			}
		}
	}


	cout << ans1 << " " << ans2;
}