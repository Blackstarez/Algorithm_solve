#include <iostream>
#include <string>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;
	int term = 'a' - 'A';
	string a, b, c;
	for (int i = 1; i <= testCase; i++)
	{
		cin >> a >> b >> c;
		cout << "#" << i << " " << (char)(a[0] - term) << (char)(b[0] - term) << (char)(c[0] - term) << "\n";
	}
}