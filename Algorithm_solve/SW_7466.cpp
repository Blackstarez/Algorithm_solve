#include <iostream>
using namespace std;
int c, n, k, r;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c;
	for (int i = 1; i <= c; i++)
	{
		r = 1;
		cin >> n >> k;
		if (n > k)r = k;
		else {
			for (int j = n; j > 0; j--) {
				if (j > k) { j = k + 1; continue; };
				if (!(k%j)) {
					r *= j;
					k /= j;
				}
			}
		}
		cout << "#" << i << " " << r << "\n";
	}
}