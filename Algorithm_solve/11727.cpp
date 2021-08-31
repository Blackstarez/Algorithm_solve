#include <iostream>
using namespace std;

int ans[1001] = { 0,1,3, };

int main()
{
	int num;
	cin >> num;
	int cnt = 1;
	for (int i = 3;i <= num;i++)
	{
		ans[i] = ((ans[i - 1] % 10007) + ((ans[i - 2]*2) % 10007)) % 10007;
	}
	cout << ans[num];
}