#include <iostream>
using namespace std;

int score[301] = { 0, };
int ans[301];
// 0 ĭ���� 1 ��ĭ ���� 2 2ĭ����
int main()
{
	int num;
	cin >> num;
	for (int i = 1;i <= num;i++)
	{
		cin >> score[i];
	}

	ans[1] = score[1];
	for (int i = 2;i <= num;i++)
	{
		if (i < 3)
		{
			ans[i] = score[i] + ans[i - 1];
		}
		else
		{
			ans[i] = score[i] + max(ans[i - 2], score[i - 1] + ans[i - 3]);
		}
	}
	cout << ans[num];
}