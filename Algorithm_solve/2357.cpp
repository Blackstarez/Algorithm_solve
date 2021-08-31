#include <iostream>
#define INT_MAX  0x7fffffff
using namespace std;

pair<long long,long long> arr[280000];

void setData(int idx, long long val)
{
	//val = val - arr[idx];
	arr[idx] = { val,val };
	while (idx != 0)
	{
		idx /= 2;
		if (arr[idx].first > val)
		{
			arr[idx].first = val;
		}
		if (arr[idx].second < val)
			arr[idx].second = val;
	}
}

// idx:트리의 배열번호, cl,cr : 해당 값이 포함하고 있는 범위, left,right
pair<long long,long long> segTree(int idx, int  cl, int  cr, int  left, int  right)
{
	if (left <= cl && cr <= right)
		return arr[idx];

	if (cr < left)return { INT_MAX,0 };
	if (cl > right)return { INT_MAX,0 };

	pair<long long, long long> v1 = segTree(idx * 2, cl, (cl + cr) / 2, left, right);
	pair<long long, long long> v2 = segTree(idx * 2 + 1, (cl + cr) / 2 + 1, cr, left, right);
	
	if (v1.first > v2.first)
	{
		if (v1.second > v2.second)
		{
			return { v2.first ,v1.second };
		}
		else
		{
			return { v2.first, v2.second };
		}
	}
	else
	{
		if (v1.second > v2.second)
		{
			return { v1.first ,v1.second };
		}
		else
		{
			return { v1.first, v2.second };
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 0;i < 280000;i++)
	{
		arr[i] = { INT_MAX, 0 };
	}

	int start = 1;
	while (start < n)
	{
		start *= 2;
	}

	for (int i = 0;i < n;i++)
	{
		int num;
		cin >> num;
		setData(start + i, num);
	}

	for (int i = 0;i < m;i++)
	{
		long long  a, b;
		cin >> a >> b;
		if (b < a)
		{
			int tmp = a;
			a = b;
			b = a;
		}
		pair<long long, long long> tmp =  segTree(1, 0, start - 1, a - 1, b - 1);
		cout << tmp.first << " " << tmp.second << "\n";
	}
}