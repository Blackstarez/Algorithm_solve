/*
�Ｚ SW Expert Academy
8458 �������� ���� ����.

���� �� �Ÿ��� ���� ��ǥ�� �հ� (abs(X),abs(Y))  = > X+Y �� max�� ����.

1���� ���ذ��� max���� ũ�ų� ������,  max�� ����(Even or Odd)�϶����� �ݺ�

�ݺ�Ƚ���� ����.
*/

#include <iostream>
using namespace std;

int abs(int num)
{
	return num > 0 ? num : -num;
}

int max, num, x, y, sum;
bool isEven = false;
bool preisEven = false;
bool impossable = false;

int main()
{
	cin.tie(false);
	cout.tie(false);
	int testCase;
	cin >> testCase;
	for (int i = 1; i <= testCase; i++)
	{
		max = 0;
		cin >> num;
		cin >> x >> y;
		sum = abs(x) + abs(y);
		max = sum;
		preisEven = (sum & 1) == 1 ? false : true;
		for (int j = 0; j < num - 1; j++)
		{
			cin >> x >> y;
			sum = abs(x) + abs(y);
			if (sum > max)
				max = sum;
			isEven = (sum & 1) == 1 ? false : true;

			if (isEven != preisEven)
				impossable = true;
			preisEven = isEven;
		}
		if (impossable)
		{
			impossable = false;
			cout << "#" << i << " " << -1 << endl;
			continue;
		}
		if (max == 0)
		{
			cout << "#" << i << " " << 0 << endl;
			continue;
		}
		sum = 0;
		if (max & 1)
			isEven = false;
		else
			isEven = true;
		int cnt = 1;
		while (sum < max || isEven == (sum & 1))
		{
			sum += cnt++;
		}
		cout << "#" << i << " " << cnt - 1 << endl;
	}
}