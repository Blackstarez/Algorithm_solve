#include <iostream>
#include <cmath>
using namespace std;

int sosu[1000001] = { 0, };

int main()
{
	sosu[1] = 1;

	int n, m;
	cin >> m >> n;
	for (int i = 2;i < sqrt(n) + 1;i++)
	{
		if (sosu[i] == 0)
		{
			int idx = i * i;
			while (idx <= n)
			{
				sosu[idx] = 1;
				idx += i;
			}
		}
	}
	for (int i = m;i <= n;i++)
	{
		if (sosu[i] == 0)
			cout << i << "\n";
	}
}