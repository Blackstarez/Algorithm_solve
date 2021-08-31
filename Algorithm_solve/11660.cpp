#include <iostream>
using namespace std;

long long sum[1025][1025] = { {0,}, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, num;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cin >> num;
			sum[i][j] = num + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}



	for (int i = 0;i < m;i++)
	{
		int x1, y1,x2,y2;
		cin >> y1 >> x1>>y2>>x2;
		cout << sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] + sum[y1 - 1][x1 - 1]<<"\n";
	}
}