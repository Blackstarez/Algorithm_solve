#include <iostream>
#include <cmath>
using namespace std;
//false √ ±‚»≠ µ 
bool sosu[10001];

int main()
{
	int idx;
	sosu[1] = true;
	for (int i = 2;i <= sqrt(10000) + 1;i++)
	{
		if (sosu[i] == false)
		{
			idx = i * i;
			while (idx <= 10000)
			{
				sosu[idx] = true;
				idx += i;
			}
		}
	}
	int testCase,q;
	cin >> testCase;
	for (int i = 0;i < testCase;i++)
	{
		cin >> q;
		idx = q / 2;
		while (idx > 1)
		{
			if (sosu[idx] == false)
			{
				if (sosu[q - idx] == false)
				{
					cout << idx << " " << q - idx << "\n";
					break;
				}
			}
			idx--;
		}
	}
}