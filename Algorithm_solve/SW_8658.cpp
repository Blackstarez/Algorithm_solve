#include <iostream>
using namespace std;

int max = 0;
int min = 99;

int main()
{
	int testCase;
	cin >> testCase;
	int sum = 0, num;
	for (int i = 1; i <= testCase; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> num;
			while (num)
			{
				sum += num - (num / 10) * 10;
				num /= 10;
				
			}
			if (max < sum)
				max = sum;
			if (min > sum)
				min = sum;
			sum = 0;
		}
		cout << "#" << i <<" "<< max << " " << min << "\n";
		max = 0;
		min = 99;
	}
}