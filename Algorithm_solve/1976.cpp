#include <iostream>
#include <vector>
using namespace std;

vector<int> city[201];
int visit[201] = { 0, };
int cty;
int ans[201] = { 0, };

void dfs(int start)
{

	ans[start] = 0;
	visit[start] = 1;
	for (int i = 0;i < city[start].size();i++)
	{
		if (!visit[city[start][i]])
		{
			dfs(city[start][i]);
		}
	}
}

int main()
{
	cin >> cty;
	int n;
	cin >> n;
	for (int i = 1;i <= cty;i++)
	{
		for (int j = 1;j <= cty;j++)
		{
			int tmp;
			cin >> tmp;
			if (tmp == 1)
			{
				city[i].push_back(j);
				city[j].push_back(i);
			}
		}
	}

	for (int i = 0;i < n;i++)
	{
		int tmp;
		cin >> tmp;
		ans[tmp] = 1;
	}

	for (int i = 1;i <= cty;i++)
	{
		if (ans[i] == 1)
		{
			dfs(i);
			break;
		}
	}
	
	for (int i = 1;i <= cty;i++)
	{
		if (ans[i] == 1)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
