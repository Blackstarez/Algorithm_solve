#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int map[21][21];
int mapSize;
int visits[21][21];
int sharkSize=2;
int eat=0;


struct Mulgogi
{
	int time;
	int x, y;
};



vector<pair<int,int>> gogi;



int bfs(pair<int,int> start)
{
	queue<Mulgogi> q;
	q.push(Mulgogi{0,start.first,start.second});
	int visit[21][21] = { 0, };
	visit[start.second][start.first] = 1;
	int minCost = 999;
	while (!q.empty())
	{
		Mulgogi m = q.front();
		q.pop();
		int x = m.x;
		int y = m.y;
		int time = m.time;
		if (minCost <= time)
			return time;


		int dx[] = { 0,-1,0,1 };
		int dy[] = { -1,0,1,0 };

		for (int i = 0;i < 4;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > mapSize || ny > mapSize || nx <= 0 || ny <= 0)
				continue;
			if (visit[ny][nx] == 1)
				continue;
			if (map[ny][nx] > sharkSize)
				continue;

			if (map[ny][nx] < sharkSize && map[ny][nx] != 0)
			{
				visit[ny][nx] = 1;
				gogi.push_back({ ny,nx });
				minCost = time + 1;
				q.push({ time + 1,nx,ny });
			}
			else
			{
				visit[ny][nx] = 1;
				q.push({ time + 1,nx,ny });
			}
		}
	}
	
	return minCost;
}


int main()
{
	int mulgogi=0,startx=0,starty=0;
	cin >> mapSize;
	for (int i = 1;i <= mapSize;i++)
	{
		for (int j = 1;j <= mapSize;j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 9)
				mulgogi++;
			if (map[i][j] == 9)
			{
				startx = j;
				starty = i;
			}
		}
	}
	map[starty][startx] = 0;
	int time = 999,before=0,ans = 0;
	do
	{
		before = ans;
		time = bfs({ startx,starty });
		if (gogi.size() == 0)
			break;

		ans += time;
		sort(gogi.begin(), gogi.end());
		pair<int,int> g = gogi.front();
		gogi.clear();
		map[g.first][g.second] = 0;
		startx = g.second;
		starty = g.first;
		

		map[starty][startx] = 9;
		map[starty][startx] = 0;
		eat++;
		if (sharkSize == eat)
		{
			sharkSize++;
			eat = 0;
		}
		
	} while (before != ans);
	cout << ans;
}