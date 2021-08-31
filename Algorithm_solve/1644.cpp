#include <iostream>
#include <vector>
using namespace std;

vector<int> sosu;
bool che[4000001];

int main()
{
	che[1] = true;
	int n;
	cin >> n;
	for (int i = 2;i * i <= n;i++)
	{
		if (che[i] == false)
		{
			int idx = i * i;
			while (idx <= n)
			{
				che[idx] = true;
				idx += i;
			}
		}
	}
	for (int i = 2;i <= n;i++)
	{
		if (che[i] == false)
			sosu.push_back(i);
	}

	int l = -1, r = -1, curNum = 0,ans = 0;
	
	while (true)
	{
		if (l == sosu.size() - 1 && r == sosu.size() - 1)
			break;
	
		if (r < (int)sosu.size()-1 && curNum <= n)
		{
			curNum += sosu[++r];
		}
		else if(l < (int)sosu.size()-1)
			curNum -= sosu[++l];

		if (curNum == n)
			ans += 1;
	}
	cout << ans;

}