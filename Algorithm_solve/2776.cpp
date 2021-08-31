#include <iostream>
#include <set>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase,n;
	cin >> testCase;
	for (int i = 0;i < testCase;i++)
	{
		set<int> s;
		cin>>n;
		for (int j = 0;j < n;j++)
		{
			int num;
			cin>>num;
			s.insert(num);
		}
		cin >> n;
		for (int j = 0;j < n;j++)
		{
			int num;
			cin>>num;
			if (s.find(num) == s.end())
				cout << "0\n";
			else
				cout<<"1\n";
		}

	}
}