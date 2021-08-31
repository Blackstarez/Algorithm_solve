#include <iostream>
using namespace std;


int arr[100];

void foo(int depth, int N,int k)
{
	if (depth == N) 
	{
		for (int i = 0;i < N;i++)
		{
			cout << arr[i];
		}
		cout << endl;
		return;
	}
	for (int i = 0;i < k;i++) {
		arr[depth] = i;
		foo(depth + 1, N,k);
	}
}

void main()
{
	foo(0, 3,7);
}