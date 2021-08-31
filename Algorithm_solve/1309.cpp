#include <iostream>
using namespace std;

int ans[100001][3] = { {0,0,0},{1,1,1}, };

int main()
{
	int n;
	cin >> n;

	for (int i = 2;i <= n;i++)
	{
		ans[i][0] = (ans[i - 1][1]+ ans[i-1][2])%9901;
		ans[i][1] = (ans[i - 1][0] + ans[i - 1][2])%9901;
		ans[i][2] = (ans[i - 1][0] + ans[i - 1][1] + ans[i - 1][2]) % 9901;
	}
	
	cout << (ans[n][0]+ ans[n][1] + ans[n][2])%9901 ;

}