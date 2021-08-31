#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	string s;
	int n,k,nk=0;
	double ans=0;

	cin >> n;
for (int i = 0;i < n;i++)
	{
		cin >> s;
		cin >> k;
		nk += k;
		cin >> s;

		if (s == "A+")
			ans += (k * 43);
		else if (s == "A0")
			ans += (k * 40);
		else if (s == "A-")
			ans += (k * 37);
		else if (s == "B+")
			ans += (k * 33);
		else if (s == "B0")
			ans += (k * 30);
		else if (s == "B-")
			ans += (k * 27);
		else if (s == "C+")
			ans += (k * 23);
		else if (s == "C0")
			ans += (k * 20);
		else if (s == "C-")
			ans += (k * 17);
		else if (s == "D+")
			ans += (k * 13);
		else if (s == "D0")
			ans += (k * 10);
		else if (s == "D-")
			ans += (k * 7);
		else if (s == "F")
			ans += 0;
		
	}
	ans = ans / nk;
	ans *= 0.1;

	printf("%.2f", ans);
	
}