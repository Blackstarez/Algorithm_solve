#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int n, num;
	vector<int> v;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());

	int maximum = 0;

	for (int i = 0;i < v.size();i++)
	{
		if (v[i] <= maximum + 1)
		{
			maximum += v[i];
		}
		else
		{
			cout << maximum + 1;
			return 0;
		}
	}
	cout << maximum + 1;
}
