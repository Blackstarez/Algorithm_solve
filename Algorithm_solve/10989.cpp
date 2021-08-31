#include <iostream>
using namespace std;

int arr[10001] = { 0, };

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> k;
		arr[k]++;
	}
	for (int i = 0;i < 10001;i++)
	{
		for (int j = 0;j < arr[i];j++)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}