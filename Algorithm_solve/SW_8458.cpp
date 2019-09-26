/*
삼성 SW Expert Academy
8458 원점으로 집합 문제.

가장 먼 거리의 점의 좌표의 합계 (abs(X),abs(Y))  = > X+Y 를 max에 저장.

1부터 더해가며 max보다 크거나 같으며,  max와 같은(Even or Odd)일때까지 반복

반복횟수가 정답.
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