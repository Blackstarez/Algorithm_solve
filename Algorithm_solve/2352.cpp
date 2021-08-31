#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> ak;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> num;
	for (int i = 0;i < num;i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0;i < num;i++)
	{
		if (ak.empty())
			ak.push_back(v[i]);
		else
		{
			int idx = upper_bound(ak.begin(), ak.end(), v[i]) - ak.begin();
			if (idx >= ak.size())
			{
				ak.push_back(v[i]);
			}
			else
				ak[idx] = v[i];
		}
	}
	cout <<ak.size();
}