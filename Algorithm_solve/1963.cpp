#include <iostream>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

bool sosu[10000];


int main()
{

	sosu[1] = true;
	for (int i = 2;i*i < 10000 ;i++)
	{
		if (sosu[i] == false)
		{
			int idx = i * i;
			while (idx < 10000)
			{
				sosu[idx] = true;
				idx += i;
			}
		}
	}

	int testCase, num1, num2;
	cin >> testCase;
	for (int k = 0;k < testCase;k++)
	{
		cin >> num1 >> num2;

		queue<pair<int, int>> q;
		q.push({ num1,0 });
		
		bool visit[10001];
		for (int i = 1000;i <= 9999;i++)
			visit[i] = false;
		visit[num1] = true;

		while (!q.empty())
		{
			pair<int,int> tmp = q.front();
			q.pop();
			int num=tmp.first, switchNum=tmp.second;

			if (num == num2)
			{
				cout << switchNum << "\n";
				break;
			}
			
			for (int i = 0;i < 4;i++)
			{
				// 각 자릿수
				for (int j = 0;j < 10;j++)
				{
					// 각 숫자
					if (i == 0 && j == 0)
						continue;

					string snum = to_string(num);
					snum[i] = '0'+j;
					int tnum = stoi(snum);

					if (!visit[tnum] && sosu[tnum] == false)
					{
						visit[tnum] = true;
						q.push({ tnum,switchNum + 1 });
					}

				}
			}


		}
	}
}