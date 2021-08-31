#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define HashMax 2123456789;


vector<long long> hashTable[100000];

bool findColl(int idx, long long hashcode)
{
	int len = hashTable[idx].size();
	for (int i = 0; i < len; i++)
	{
		if (hashTable[idx][i] == hashcode)
			return true;
	}
	hashTable[idx].push_back(hashcode);
	return false;
}


bool solve(const char* str, int hashLen)
{
	int len = strlen(str);

	long long val = 0;
	long long keyMax = 1;
	int Idx = 0;
	int IDXMAX = 1;

	for (int i = 0; i < hashLen; i++) {
		val *= 61;
		val %= HashMax;
		val += str[i];
		keyMax *= 61;
		keyMax %= HashMax;
		Idx *= 17;
		Idx %= 100000;
		Idx += str[i];
		Idx %= 100000;
		IDXMAX *= 17;
		IDXMAX %= 100000;
	}

	if (findColl(Idx, val))
		return true;

	int front = 0;
	for (int rear = hashLen; rear < len; rear++)
	{
		val = (val * 61) % HashMax;
		Idx = (Idx * 17) % 100000;
		val -= (keyMax * str[front]) % HashMax;
		Idx -= (IDXMAX * str[front++]) % 100000;
		if (val < 0)
		{
			val += HashMax;
		}
		if (Idx < 0)
			Idx += 100000;
		Idx += str[rear];
		Idx %= 100000;
		val += str[rear];
		val %= HashMax;

		if (findColl(Idx, val))
			return true;
	}
	return false;
}

int main()
{
	int strLen, size, front = 0, rear;
	cin >> strLen;
	rear = strLen - 1;
	char* c = new char[strLen + 1];
	scanf("%s", c);
	int ans = 0;
	while (front <= rear)
	{
		size = (front + rear) / 2;

		if (size == 1)
			break;
		for (int i = 0; i < 100000; i++)
		{
			hashTable[i].clear();
		}
		if (solve(c, size))
		{
			front = size + 1;
			if (ans < size)
				ans = size;
		}
		else
			rear = size - 1;
	}
	cout << ans;
	return 0;
}