#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,string>> ans;
int LCS[1001][1001] = { {0,}, };

bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first > b.first;
}

int main()
{
	string s1, s2, lcs = "";
	cin >> s1 >> s2;
	int maxVal = 0;

	for (int i = 0;i < s1.length();i++)
	{
		for (int j = 0;j < s2.length();j++)
		{
			if (s1[i] == s2[j])
			{
				LCS[i + 1][j + 1] = LCS[i][j] + 1;
				if (maxVal < LCS[i + 1][j + 1])
				{
					maxVal = LCS[i + 1][j + 1];
				}
			}
			else
			{
				LCS[i + 1][j + 1] = max(LCS[i][j + 1], LCS[i + 1][j]);
			}
		}
	}

	cout << maxVal << "\n";

	int i=s1.length(), j=s2.length();
	string ans = "";
	while (true)
	{
		if (i == 0 || j == 0)
			break;
		if (LCS[i][j] == 0)
			break;
		if (LCS[i][j] == LCS[i - 1][j])
			i--;
		else if (LCS[i][j] == LCS[i][j - 1])
			j--;
		else
		{
			ans += s1[i-1];
			i--;
			j--;
		}
	}
	for (int k = ans.length() - 1;k >= 0;k--)
		cout << ans[k];

}