#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
vector<int> ak;

int main()
{
	int num;
	cin >> num;
	for (int i = 0;i < num;i++)
	{
		int a,b;
		cin >> a>>b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());
	for (int i = 0;i < num;i++)
	{
		if (ak.empty())
			ak.push_back(v[i].second);
		else
		{
			int idx = upper_bound(ak.begin(), ak.end(), v[i].second) - ak.begin();
			if (idx >= ak.size())
			{
				ak.push_back(v[i].second);
			}
			else
				ak[idx] = v[i].second;
		}
	}
	cout << num - ak.size();
}