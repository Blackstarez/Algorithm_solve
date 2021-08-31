#include <iostream>
using namespace std;

long long sum[100001] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int tmp;
		
	for (int i = 1;i <= n;i++)
	{
		cin >> tmp;
		sum[i] = sum[i - 1] + tmp;
	}
	for (int i = 0;i < m;i++)
	{
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a-1] << "\n";
	}
}