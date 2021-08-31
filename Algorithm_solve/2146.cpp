#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int mapSize;
int visit[101][101];
int colorMap[60];

struct CostMap
{
	int cost;
	int x, y;
};


int bfs(pair<int,int> start,int color)
{
	queue<CostMap> q;
	for (int i = 0;i < 101;i++)
	{
		for (int j = 0;j < 101;j++)
			visit[i][j] = 0;
	}
	visit[start.second][start.first] = 1;
	q.push(CostMap{ 0,start.first,start.second });

	int minCost = 0x7ffffff;

	while (!q.empty())
	{
		CostMap c = q.front();
		q.pop();
		int cost = c.cost; int x = c.x; int y = c.y;
		
		// ´Ù¸¥ ¼¶¿¡ µµÂøÇÑ °æ¿ì
		if (map[y][x] != color && map[y][x] != 0)
		{
			if (cost < minCost)
			{
				minCost = cost;
			}
			continue;
		}

		int dx[] = { 1,0,-1,0 };
		int dy[] = { 0,1,0,-1 };

		for (int i = 0;i < 4;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > mapSize || ny > mapSize || nx < 1 || ny < 1)
				continue;
			if (visit[ny][nx] == 1)
				continue;
			
			if (color == map[ny][nx])
			{
				q.push(CostMap{ 0,nx,ny });
			}
			else
			{
				q.push(CostMap{ cost + 1,nx,ny });
			}
			visit[ny][nx] = 1;
		}

	}

	return minCost-1;
}

void setBfs(pair<int, int> start, int color)
{
	queue<pair<int, int>> q;
	
	map[start.second][start.first] = color;
	visit[start.second][start.first]=1;
	q.push(start);
	while (!q.empty())
	{
		pair<int, int> t = q.front();
		q.pop();
		int x = t.first;int y = t.second;
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };
		
		for (int i = 0;i < 4;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > mapSize || ny > mapSize || nx < 1 || ny < 1)
				continue;
			if (visit[ny][nx] == 1)
				continue;
			if (map[ny][nx] == 1)
			{
				visit[ny][nx] = 1;
				q.push({ nx,ny });
				map[ny][nx] = color;
			}
		}
	}
}

void printMap()
{
	for (int i = 1;i <= mapSize;i++)
	{
		for (int j = 1;j <= mapSize;j++)
			cout << map[i][j] << " ";
		cout << endl;
	}cout << endl;
}


int main()
{
	cin >> mapSize;
	for (int i = 1;i <= mapSize;i++)
	{
		for (int j = 1;j <= mapSize;j++)
		{
			cin >> map[i][j];
		}
	}

	int cnt = 2;
	for (int i = 1;i <= mapSize;i++)
	{
		for (int j = 1;j <= mapSize;j++)
		{
			if (!visit[i][j] && map[i][j] == 1)
			{
				setBfs({ j,i }, cnt);
				cnt++;
			}
		}
	}

	int ans = 0x7fffffff;
	for (int i = 1;i <= mapSize;i++)
	{
		for (int j = 1;j <= mapSize;j++)
		{
			if (!colorMap[map[i][j]] && map[i][j] != 0)
			{
				colorMap[map[i][j]] = 1;
				int tmp = bfs({ j,i }, map[i][j]);
				if (tmp < ans)
					ans = tmp;
			}
		}
	}
	cout << ans;
}