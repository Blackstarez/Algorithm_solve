#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool gte(const int& a, const int& b)
{
	return a > b;
}

int main()
{
	int testCase;
	cin >> testCase;
	for (int t = 0;t < testCase;t++)
	{
		vector<int> a;
		vector<int> b;
		int n, m;
		cin >> n >> m;
		for (int i = 0;i < n;i++)
		{
			int num;
			cin >> num;
			a.push_back(num);
		}
		for (int i = 0;i < m;i++)
		{
			int num;
			cin >> num;
			b.push_back(num);
		}

		sort(a.begin(), a.end(), gte);
		sort(b.begin(), b.end(), gte);



		int ans = 0;
		int l=0, r=0;
		int v = b.size();


		while (true)
		{
			if (l == a.size())
				break;
			if (r == b.size())
				break;
			if (a[l] > b[r])
			{
				ans += v;
				l++;
			}
			else
			{
				r++;
				v--;
			}
		}
		
		cout << ans<<endl;
	}
}
