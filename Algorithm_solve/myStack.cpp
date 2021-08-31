#include <iostream>
#include <string>
using namespace std;

int alpha[26] = { 0 , };


int main()
{
	string s;
	cin >> s;
	for (int i = 0;i < s.length();i++)
	{
		alpha[s[i] - 'A']++;
	}


	int middle = -1;
	for (int i = 0;i < 26;i++)
	{
		if (alpha[i] % 2 == 1)
		{
			if (middle != -1)
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			middle = i;
		}
	}
	char* ans = new char[s.length()];
	int idx = 0;
	for (int i = 0;i < 26;i++)
	{
		for (int j = alpha[i]/2;j > 0;j--) {
			ans[idx++] = i + 'A';
		}
	}
	if( middle != -1)
	ans[idx++] = middle + 'A';

	//홀수 길이인경우
	if (s.length() % 2 == 1)
	{
		idx--;
		for (int i = 1;i<=idx;i++)
		{
			ans[idx + i] = ans[idx - i];
		}
	}
	else {
		for (int i = 1;i <= idx;i++)
		{
			ans[idx + i-1] = ans[idx - i];
		}
	}

	for (int i = 0;i < s.length();i++)
		cout << ans[i];

}