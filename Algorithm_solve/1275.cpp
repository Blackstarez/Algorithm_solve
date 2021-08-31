#include <iostream>
using namespace std;

long long arr[280000] = { 0, };

void setData(int idx, long long val)
{
	val = val - arr[idx];

	while (idx != 0)
	{
		arr[idx] += val;
		idx /= 2;
	}
}

// idx:트리의 배열번호, cl,cr : 해당 값이 포함하고 있는 범위, left,right
long long segTree(int idx, int  cl, int  cr, int  left, int  right)
{
	if (left <= cl && cr <= right)
		return arr[idx];

	if (cr < left)return 0;
	if (cl > right)return 0;

	long long v1 = segTree(idx * 2, cl, (cl + cr) / 2, left, right);
	long long v2 = segTree(idx * 2 + 1, (cl + cr) / 2 + 1, cr, left, right);

	return v1 + v2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

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
		long long x, y, a, b;
		cin >> x >> y >> a >> b;
		if (y < x)
		{
			int tmp = x;
			x = y;
			y = tmp;
		}
		cout << segTree(1, 0, start - 1, x - 1, y - 1) << "\n";
		setData(start + a - 1, b);	
		
	}
}