/*
 백준 16282번 문제 Black chain 

 현재 미완성 - 메모리 초과로 실패

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, a, b;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	int x = abs(a.first - a.second) - abs(b.first - b.second);
	if (x < 0)
	{
		return true;
	}
	else if (x > 0)
	{
		return false;
	}
	else
	{
		return (a.first + a.second > b.first + b.second);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end(), cmp);
	
	a = 0; b = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (a + v[i].first <= b + v[i].second)
		{
			a += v[i].first;
		}
		else
			b += v[i].second;
	}

	cout << max(a, b);
}