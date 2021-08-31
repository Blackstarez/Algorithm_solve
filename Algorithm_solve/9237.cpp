#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int comPare(void* a, void* b)
{
	int num1 = *(int *)a, num2 = *(int*)b;
	if (num1 < num2)
		return 1;
	else if (num1 > num2)
		return -1;
	else
		return 0;
}

int main()
{
	int n,num,max = 0;
	cin >> n;
	vector<int> v;

	for (int i = 0;i < n;i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end(),greater<int>());
	for (int i = 0;i < v.size();i++)
	{
		if (1 + i + v[i] > max)
		{
			max = 1 + i + v[i];
		}
	}
			
	cout << max+1 ;
}