/*
SW Expert Academy
2072 Ȧ���� ���ϱ�

Ȧ���̸� ���ؼ� ����Ѵ�.

*/
#include <iostream>
using namespace std;

int main()
{
	int testCase, num,sum;
	cin >> testCase;
	for (int i = 1; i <= testCase; i++)
	{
		sum = 0;
		for (int j = 0; j < 10; j++)
		{
			cin >> num;
			if (num & 1)
				sum += num;
		}
		cout << "#" << i << " " << sum << "\n";
	}
}