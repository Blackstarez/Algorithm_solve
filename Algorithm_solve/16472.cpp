#include <iostream>
#include <string>
#include <set>
using namespace std;

int alpha[26] = {0,};
set<int> s;

int main()
{
	int num;
	string str;
	cin >> num;
	cin >> str;
	int ans=0, tmp=0;
	int l = 0, r = 0;

	while (l < str.length())
	{
		if (r == str.length())
			break;
		if (s.size() < num)
		{
			s.insert(str[r] - 'a');
			tmp += 1;
			alpha[str[r] - 'a'] += 1;
			r++;
		}
		else if (s.find(str[r]-'a') == s.end())//없는경우
		{
			while (s.size() == num)
			{
				alpha[str[l] - 'a'] -= 1;
				tmp -= 1;
				if (alpha[str[l] - 'a'] == 0)
				{
					s.erase(str[l] - 'a');
				}
				l++;
			}
		}
		else
		{
			alpha[str[r] - 'a'] += 1;
			tmp += 1;
			r++;
		}
		if (tmp > ans)
			ans = tmp;
	}
	cout << ans;
	return 0;
}