#include <iostream>
#include <string>
using namespace std;



int main()
{
	int testCase, k;
	string a;
	cin >> testCase;
	for (int i = 1; i <= testCase; i++)
	{
		int num[10] = { 0,0,0,0,0,0,0,0,0,0 };
		int cnt = 0;
		cin >> a;
		for (int j = 0; j < a.length(); j++)
		{
			if (num[a[j]-'0'])
				num[a[j] - '0'] = false;
			else
				num[a[j] - '0'] = true;
		}
		for (int j = 0; j < 10; j++)
		{
			if (num[j])
			{
				cnt++;
			}
		}
		cout << "#" << i << " " << cnt << "\n";
	}
}