#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> stack;
	int n,num,sum = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> num;
		if (num == 0)
			stack.pop();
		else
			stack.push(num);
	}
	while (!stack.empty())
	{
		sum += stack.top();
		stack.pop();
	}
	cout << sum;
	return 0;
}