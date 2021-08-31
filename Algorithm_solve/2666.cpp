#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int door[21];
int goal[21];

int dfs(pair<int,int> open,int cost,int goalNum,int end)
{
	if (goalNum == end)
		return cost;

	return min(dfs({goal[goalNum],open.second}, cost+abs(open.first - goal[goalNum]), goalNum + 1, end),
		dfs({ open.first,goal[goalNum] },cost+abs(open.second-goal[goalNum]),goalNum+1,end));
}

int main()
{
	int n,a,b,m;
	cin >> n>>a>>b>>m;

	for (int i = 0;i < m;i++)
	{
		cin >> goal[i];
	}
	int ans;
	ans = dfs({ a,b }, 0, 0, m);
	cout << ans;

}