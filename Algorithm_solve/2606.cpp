#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[101];
int visit[101] = { 0, };
int cmax;

int main()
{
	cin >> cmax;
	int n,a,b,ans = 0;
	cin >> n;

	queue<int> s;

	for (int i = 0;i < n;i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	s.push(1);
	visit[1] = 1;
	while (!s.empty())
	{
		a = s.front();
		s.pop();
		for (int i = 0;i < v[a].size();i++)
		{
			if (visit[v[a][i]] == 0)
			{
				visit[v[a][i]] = 1;
				s.push(v[a][i]);
				ans++;
			}
		}
	}
	cout << ans;

}