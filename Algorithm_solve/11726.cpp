#include <iostream>
using namespace std;

int ans[1001] = { 0,1,2, };

int main()
{
	int num;
	cin >> num;
	for (int i = 3;i <= num;i++)
	{
		ans[i] = ((ans[i - 1] % 10007) + (ans[i - 2] % 10007)) % 10007;
	}
	cout << ans[num];
}