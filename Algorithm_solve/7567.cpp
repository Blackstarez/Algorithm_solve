#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int height = 10;
	bool sight;
	
	if (s[0] == '(')
		sight = true;
	else
		sight = false;

	for (int i = 1;i < s.length();i++)
	{
		height += 10;
		if (s[i] == '(')
		{
			if (sight == true)
				height -= 5;
			else
			{
				sight = true;
			}
		}
		else 
		{
			if (sight == true)
			{
				sight = false;
			}
			else
				height -= 5;
		}
	}
	cout << height;
}