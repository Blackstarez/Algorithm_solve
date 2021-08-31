#include <iostream>
using namespace std;

int ans[101][10] = { {0,},{0,1,1,1,1,1,1,1,1,1}, };

int main()
{
	int num;
	cin >> num;

	for (int i = 2;i <= num;i++)
	{
		ans[i][0] = ans[i - 1][1];
		ans[i][9] = ans[i - 1][8];
		ans[i][1] = (ans[i - 1][0] + ans[i - 1][2]) % 1000000000;
		ans[i][2] = (ans[i - 1][1] + ans[i - 1][3]) % 1000000000;
		ans[i][3] = (ans[i - 1][2] + ans[i - 1][4]) % 1000000000;
		ans[i][4] = (ans[i - 1][3] + ans[i - 1][5]) % 1000000000;
		ans[i][5] = (ans[i - 1][4] + ans[i - 1][6]) % 1000000000;
		ans[i][6] = (ans[i - 1][5] + ans[i - 1][7]) % 1000000000;
		ans[i][7] = (ans[i - 1][6] + ans[i - 1][8]) % 1000000000;
		ans[i][8] = (ans[i - 1][7] + ans[i - 1][9])% 1000000000;
	}

	int a=0;
	for (int i = 0;i < 10;i++)
	{
		a = (a+ans[num][i]) % 1000000000;
	}
	cout << a;
}