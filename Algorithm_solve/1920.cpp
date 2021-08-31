#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	set<int> s;
	int n, m;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int num;
		cin >> num;
		s.insert(num);
	}
	cin >> m;
	for (int i = 0;i < m;i++)
	{
		int num;
		cin >> num;
		if (s.find(num) == s.end())
			cout << "0\n";
		else
			cout << "1\n";
	}
}