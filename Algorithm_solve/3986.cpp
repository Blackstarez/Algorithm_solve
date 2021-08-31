#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	stack<char> s;
	string str;
	int n,ans = 0;
	char a;
	cin >> n;
	cin.get();

	for (int i = 0;i < n;i++)
	{
		cin >> str;
		for (int j = 0;j < str.length();j++)
		{
			a = str[j];
			if (s.empty())
				s.push(a);
			else
			{
				if (s.top() == a)
				{
					s.pop();
				}
				else
				{
					s.push(a);
				}
			}		
		}
		if (s.empty())
			ans++;
		else
		{
			while (!s.empty())
				s.pop();
		}
	}
	cout << ans;
}