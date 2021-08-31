#include <iostream>
#include <queue>
using namespace std;

#define INT_MAX 0x7fffffff
int time[200001];
priority_queue<pair<int, int>> pq;

int main()
{
	int subin, dongsang;
	cin >> subin >> dongsang;
	for (int i = 0;i < 200001;i++)
	{
		time[i] = INT_MAX;
	}
	
	pq.push({ 0,subin });
	time[subin] = 0;

	while (!pq.empty())
	{
		pair<int, int> tmp = pq.top();
		pq.pop();
		subin = tmp.second;
		int t = -tmp.first;
		
		if (t > time[subin])
			continue;
		if (subin == dongsang)
		{
			cout << t;
			break;
		}

		if (subin<200000 && time[subin+1] > t + 1)
		{
			time[subin+1] = t + 1;
			pq.push({ -time[subin + 1],subin + 1 });
		}
		if (subin >= 1 && time[subin - 1] > t + 1)
		{
			time[subin - 1] = t + 1;
			pq.push({ -time[subin - 1],subin - 1 });
		}
		if (subin <= 100000 && subin > 0 && time[subin * 2] > t)
		{
			time[subin * 2] = t;
			pq.push({ -time[subin * 2],subin*2 });
		}
	}
}