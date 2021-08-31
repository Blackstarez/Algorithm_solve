#include <iostream>
#include <string>
using namespace std;

int LCS[101][101][101] = { {0,}, };

int main()
{
	string s1, s2,s3;
	cin >> s1 >> s2>>s3;
	int maxVal = 0;

	for (int i = 0;i < s1.length();i++)
	{
		for (int j = 0;j < s2.length();j++)
		{
			for (int k = 0;k < s3.length();k++)
			{
				if (s1[i] == s2[j] && s1[i] == s3[k])
				{
					LCS[i + 1][j + 1][k + 1] = LCS[i][j][k] + 1;
					if (maxVal < LCS[i + 1][j + 1][k + 1])
					{
						maxVal = LCS[i + 1][j + 1][k + 1];
					}
				}
				else
				{	
					int di[] = { 0,0,1,1,0,1 };
					int dj[] = { 0,1,0,1,1,0 };
					int dk[] = { 1,0,0,0,1,1 };
					int val = 0;
					for (int z = 0;z < 6;z++)
					{
						if (LCS[i + di[z]][j + dj[z]][k + dk[z]] > val)
							val = LCS[i + di[z]][j + dj[z]][k + dk[z]];
					}
					LCS[i + 1][j + 1][k + 1] = val;
				}
			}
			
		}
	}

	cout << maxVal;

}