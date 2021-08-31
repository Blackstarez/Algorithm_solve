#include <iostream>
#include <string>
#include <stack>
using namespace std;



int main()
{
	stack<char> s1, s2;
	string s;
	cin >> s;
	for (int i = 0;i < s.length();i++)
		s1.push(s[i]);
	
	int n;
	char op;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		cin >> op;
		
		if (op == 'L')
		{
			if (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		else if (op == 'D')
		{
			if (!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
		else if (op == 'B')
		{
			if(!s1.empty())
				s1.pop();
		}
		else 
		{
			cin >> op;
			s1.push(op);
		}
	}
	while (!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	
	while (!s2.empty())
	{
		cout << s2.top();
		s2.pop();
	}
	return 0;
}