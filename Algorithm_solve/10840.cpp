#include <iostream>
#include <vector>
#include <string>
using namespace std;

int alpha[26] = {53,223,13,229,233,239,7,251,2221,263,3171,271,90,281,2887,293,351,311,867,317,882,9217,347,654,353,2777};
int beta[26] = {1171,3175,2884,334,12,1147,1672,3487,315,798,135,81245,6154,35,326,256,592,23,23,75,25,305,265,652,991,817};
vector<int> hashTable[100000];

bool check_coll(int idx, int hashCode)
{
	for (int i = 0;i < hashTable[idx].size();i++)
	{
		if (hashTable[idx][i] == hashCode)
			return true;
	}
	return false;
}

bool solve(const string str, const string str2,int length)
{
	int hk[2] = { 11717,2731 };
	int hm[2] = { 93131, 127132452};
	int val=0,idx=0;
	for (int i = 0;i < length;i++)
	{
		idx += hk[0] * alpha[str[i]-'a'];
		val += hk[1] * beta[str[i] - 'a'];
		idx %= hm[0];
		val %= hm[1];
	}
	hashTable[idx].push_back(val);

	for (int i = length;i < str.length();i++)
	{
		
		idx -= (hk[0] * alpha[str[i-length] - 'a'])%hm[0];
		val -= (hk[1] * beta[str[i-length] - 'a'])%hm[1];
		
		idx += hk[0] * alpha[str[i] - 'a'];
		val += hk[1] * beta[str[i] - 'a'];
		
		idx += hm[0];
		val += hm[1];
		
		idx %= hm[0];
		val %= hm[1];
	
		hashTable[idx].push_back(val);
	}

	val = 0, idx = 0;
	for (int i = 0;i < length;i++)
	{
		idx += hk[0] * alpha[str2[i] - 'a'];
		val += hk[1] * beta[str2[i] - 'a'];
		idx %= hm[0];
		val %= hm[1];
	}
	if (check_coll(idx, val))
		return true;

	for (int i = length;i < str2.length();i++)
	{

		idx -= (hk[0] * alpha[str2[i - length] - 'a'])%hm[0];
		val -= (hk[1] * beta[str2[i - length] - 'a'])%hm[1];
		idx += hk[0] * alpha[str2[i] - 'a'];
		val += hk[1] * beta[str2[i] - 'a'];
		idx += hm[0];
		val += hm[1];
		idx %= hm[0];
		val %= hm[1];

		if (check_coll(idx, val))
			return true;
	}
	return false;
}

int main()
{

	string a, b;
	cin >> a >> b;

	int ans=0;
	int front = 0,rear = a.length() > b.length() ? b.length() : a.length();
	
	
	for (int i = rear;i > 0;i--)
	{
		for (int i = 0; i < 100000; i++)
		{
			hashTable[i].clear();
		}

		if (solve(a, b, i))
		{
			cout << i;
			return 0;	
		}
	}
	cout << ans;
}