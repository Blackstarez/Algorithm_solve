#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INT_MAX 0x7fffffff

struct Pos {
	int x, y;
	int cost;
};



bool operator<(const Pos& p1, const Pos& p2)
{
	return p1.cost > p2.cost;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase = 1;
	while (true)
	{
		priority_queue<Pos> pq;
		int map[126][126];
		int ans[126][126];
		int n;
		cin >> n;
		if (n == 0)
			return 0;

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				cin >> map[i][j];
				ans[i][j] = INT_MAX;
			}
		}

		ans[0][0] = map[0][0];
		pq.push({ 0,0,ans[0][0] });
		while (!pq.empty())
		{
			Pos tmp = pq.top();
			pq.pop();
			if (tmp.x == n - 1 && tmp.y == n - 1)
				break;
			if (tmp.cost > ans[tmp.y][tmp.x])
				continue;
			int dx[] = { 0,1,0,-1 };
			int dy[] = { 1,0,-1,0 };
			for (int i = 0;i < 4;i++)
			{
				int nx = tmp.x + dx[i];
				int ny = tmp.y + dy[i];
				int cost = tmp.cost;

				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;

				if (ans[ny][nx] > map[ny][nx] + cost)
				{
					ans[ny][nx] = map[ny][nx] + cost;
					pq.push(Pos{ nx, ny, ans[ny][nx] });
				}
			}
		}

		cout << "Problem " << testCase << ": " << ans[n - 1][n - 1] << "\n";
		testCase += 1;
	}
}