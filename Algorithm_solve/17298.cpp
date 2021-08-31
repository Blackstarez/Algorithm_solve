#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> s1, s2,ans;
	int num, n;
	cin >> n;
	for (int i = 0;i < n;i++) 
	{
		cin >> num;
		s1.push(num);
	}

	while (!s1.empty())
	{
		num = s1.top();
		s1.pop();

		if (s2.empty())
		{
			ans.push(-1);
			s2.push(num);
		}
		else
		{
			if (s2.top() > num)
			{
				ans.push(s2.top());
				s2.push(num);
			}
			else
			{
				while (num >= s2.top())
				{
					s2.pop();
					if (s2.empty())
						break;
				}

				if (s2.empty())
				{
					ans.push(-1);
					s2.push(num);
				}
				else
				{
					ans.push(s2.top());
					s2.push(num);
				}
			}
		}
	}
	while (!ans.empty())
	{
		cout << ans.top()<<" ";
		ans.pop();
	}
}