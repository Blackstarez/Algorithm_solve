#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr[7];
bool visit[7] = { false, };

void dfs(vector<int> arr[], int point)
{
	cout << point << " ";
	visit[point] = true;

	for (int i = 0;i < arr[point].size();i++)
	{
		if (!visit[arr[point][i]])
		{
			
			dfs(arr, arr[point][i]);
		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(arr,1);


	/*
	for (int i = 0;i < m;i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}

	for (int i = 0;i < m;i++)
	{
		cout << i << " : ";
		for (int j = 0;j < arr[i].size();j++)
		{
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
	*/
}