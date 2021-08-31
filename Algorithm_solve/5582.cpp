#include <iostream>
#include <string>
using namespace std;

int ans[4001][4001] = { 0, };

int main()
{
	string s1, s2;
	int maxNum = 0;
	cin >> s1 >> s2;

	for (int i = 0;i < s1.length();i++)
	{
		for (int j = 0;j < s2.length();j++)
		{
			if (s1[i] == s2[j])
			{
				ans[i + 1][j + 1] = ans[i][j] + 1;
				if (maxNum < ans[i + 1][j + 1])
					maxNum = ans[i + 1][j + 1];
			}
			else
			{
				ans[i + 1][j + 1] =0;
			}
		}
	}
	cout << maxNum;
}