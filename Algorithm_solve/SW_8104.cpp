/*
SW Expert Academy 
8104 조 만들기

조의 갯수가 짝수인지 홀수인지에 따라 출력이 달라진다.
짝수개의 조인경우 모든 조의 실력이 동일하나, 홀수개인경우 1조부터 실력이 올라가는 식이다.

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