#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int siz, cnt;
int map[26][26];
int dangi[400];

void bfs(int x, int y)
{
	queue<pair<int,int>> q;
	q.push({ x,y });
	map[y][x] = 0;
	dangi[cnt] += 1;
	while (!q.empty())
	{
		pair<int,int> next = q.front();
		q.pop();
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };
		for (int i = 0; i < 4; i++)
		{
			int nx = next.first + dx[i], ny = next.second + dy[i];

			if (ny < 0 || nx < 0 || ny >= siz || nx >= siz)
				continue;
			if (map[ny][nx])
			{
				map[ny][nx] = 0;
				q.push({ nx, ny });
				dangi[cnt] += 1;
			}
		}
	}

}


int main()
{
	char num;
	cin >> siz;
	for (int i = 0; i < siz; i++)
	{
		for (int j = 0; j < siz; j++)
		{
			cin >> num;
			if (num == '1')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
	cnt = 0;
	for (int i = 0; i < siz; i++)
	{
		for (int j = 0; j < siz; j++)
		{
			if (map[i][j])
			{
				bfs(j, i);
				cnt++;
			}
		}
	}
	sort(&dangi[0], &dangi[cnt]);

	cout << cnt;
	for (int i = 0; i < cnt; i++)
	{
		cout << "\n" << dangi[i];
	}
}