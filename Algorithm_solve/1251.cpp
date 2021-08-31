#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s,s2,ans="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	int i, j, k;
	cin >> s;
	
	for (i =1 ;i < s.length()-1;i++)
	{
		for (j = i + 1;j < s.length();j++)
		{
			s2 = s;
			reverse(&s2[0], &s2[i]);
			reverse(&s2[i], &s2[j]);
			reverse(&s2[j], &s2[s2.length()]);
			if (s2.compare(ans) < 0)
				ans = s2;
		}
	}
	cout << ans;
}