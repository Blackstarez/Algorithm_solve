/*
SW Expert Academy
1217 �ŵ�����

���ȣ���� ���� ��������.

*/
#include <iostream>
using namespace std;

int ans;

int mul(int num, int n)
{
	if (n == 0)
		return 1;
	return num * mul(num, n - 1);
}

int main()
{
	int x, y,testCase;
	for (int i = 1; i <= 10; i++)
	{
		cin >>testCase>> x >> y;
		ans = mul(x, y);
		cout << "#" << testCase << " " << ans << endl;
	}
}