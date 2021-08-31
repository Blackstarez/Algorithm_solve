#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	string str = "HelloWorld";
	int hk[1] = { 17 };
	int hm [1]= { 21956 };
	int hk4[1] = { 1 };

	for (int j = 0;j < 1;j++)
	{
		int s = 0;
		for (int i = 0;i < 4;i++)
		{
			s *= hk[j];
			s += str[i];
			s %= hm[j];
			hk4[j] *= hk[j];
			hk4[j] %= hm[j];
		}
		cout << s << endl;

		for (int i = 4; i < str.length();i++)
		{
			s *= hk[j];
			s -= (str[i - 4] * hk4[j]) % hm[j];
			s += str[i];
			s += hm[j];
			s %= hm[j];
			cout << s << endl;
		}




		cout << "hk : " << hk[j] << endl;
		cout << "hk4 : " << hk4[j] << endl;
		cout << "hm : " << hm[j] << endl;
	}
	
}