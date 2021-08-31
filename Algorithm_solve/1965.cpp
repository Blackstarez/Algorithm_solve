#include <iostream>
using namespace std;

int box[1001][2];

int main()
{
	int num,maxi=0;
	cin >> num;
	for (int i = 0;i < num;i++)
	{
		cin >> box[i][0];
		box[i][1] = 1;
		int max = 0;
		for (int j = i - 1;j >= 0;j--)
		{
			if (box[j][0] < box[i][0])
			{
				if (max < box[j][1])
					max = box[j][1];
			}
		}
		box[i][1] += max;
		if (box[i][1] > maxi)
			maxi = box[i][1];
	}

	cout << maxi;
}