/*
SW Expert Academy 
8104 �� �����

���� ������ ¦������ Ȧ�������� ���� ����� �޶�����.
¦������ ���ΰ�� ��� ���� �Ƿ��� �����ϳ�, Ȧ�����ΰ�� 1������ �Ƿ��� �ö󰡴� ���̴�.

*/

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testCase;
	cin >> testCase;
	int n, k,sum;
	for (int i = 1; i <= testCase; i++)
	{
		sum = 0;
		cin >> n >> k;
		
		sum = (((n*k)*(n*k + 1)) / 2) / k;
		cout << "#" << i;
		if (n & 1)
		{
			int add;
			if (k & 1)
				add = -(k / 2);
			else
				add = -(k / 2) + 1;
			for (int j = 0; j < k; j++)
			{
				cout << " " << sum + add;
				add++;
			}
		}
		else
		{
			for (int j = 0; j < k; j++)
				cout << " " << sum;
		}
		cout << endl;
	}
	return 0;
}