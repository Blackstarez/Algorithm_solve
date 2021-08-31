#include <iostream>
#include <string>
using namespace std;

int hm[2] = { 713771, 2176451 };
int hk[2] = { 317,719 };
int hk4[2] = { 1 ,1 };
int length;

int main()
{
	string word, ans;
	cin >> word;
	cin >> ans;


	int ansHash[2] = { 0,0 }, qHash[2] = { 0 ,0 };
	length = word.length();

	for (int j = 0;j < ans.length();j++)
	{
		for (int i = 0;i < 2;i++)
		{
			ansHash[i] *= hk[i];
			ansHash[i] += ans[j];
			ansHash[i] %= hm[i];
			hk4[i] *= hk[i];
			hk4[i] %= hm[i];

			qHash[i] *= hk[i];
			qHash[i] += word[j];
			qHash[i] %= hm[i];
		}

	}
	if (qHash[0] == ansHash[0] && qHash[1] == ansHash[1])
	{
		cout << 1;
		return 0;
	}

	for (int j = ans.length();j < length;j++)
	{
		for (int i = 0;i < 2;i++)
		{
			qHash[i] *= hk[i];
			qHash[i] -= (word[j - ans.length()] * hk4[i]) % hm[i];
			qHash[i] += word[j];
			qHash[i] += hm[i];
			qHash[i] %= hm[i];

		}
		if (qHash[0] == ansHash[0] && qHash[1] == ansHash[1])
		{
			cout << 1;
			return 0;
		}

	}
	cout << 0;
	return 0;
}