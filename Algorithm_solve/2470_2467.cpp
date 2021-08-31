#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> mnus;
vector<int> pus;
pair<int, int> ans;

bool desc(const int& a, const int& b)
{
	return a > b;
}


int main()
{
	int n,m;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> m;
		if (m < 0)
			mnus.push_back(m);
		else
			pus.push_back(m);
	}



	// 오름차순 정렬
	sort(pus.begin(), pus.end());
	// 내림차순 정렬
	sort(mnus.begin(), mnus.end(), desc);

	if (mnus.size() == 0)
	{
		cout << pus[0] << " " << pus[1];
		return 0;
	}
	else if (pus.size() == 0)
	{
		cout << mnus[1] << " " << mnus[0];
		return 0;
	}

	int l = 0, r = 0,cha=mnus[l]+pus[r],minCha=abs(cha);
	int tmp1= mnus[l], tmp2 = pus[r];
	ans = { mnus[l] ,pus[r] };

	while (true)
	{
		if (cha == 0)
		{
			cout <<ans.first << " " << ans.second;
			return 0;
		}
		
		if (cha < 0 && r == pus.size()-1)
			break;
		if (cha > 0 && l == mnus.size()-1)
			break;

		if (cha > 0)
		{
			tmp1 = mnus[++l];
			cha = tmp1 + tmp2;
			
		}
		else if (cha < 0)
		{
			tmp2 = pus[++r];
			cha = tmp1 + tmp2;
		}
		
		if (abs(cha) < minCha)
		{
			minCha = abs(cha);
			ans = { tmp1,tmp2 };
		}
	}
	
	if (mnus.size() >= 2)
	{
		if (minCha > abs(mnus[0] + mnus[1]))
		{
			ans = { mnus[1],mnus[0] };
			minCha = abs(mnus[0] + mnus[1]);
		}
	}

	if (pus.size() >= 2)
	{
		if (minCha > pus[0] + pus[1])
		{
			ans = { pus[0],pus[1] };
			minCha = pus[0] + pus[1];
		}
	}




	cout << ans.first << " " << ans.second;

}