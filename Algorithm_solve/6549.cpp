#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
	int cases = 0;
	while (true) {
		// 초기화
		long long ans = 0;
		stack<pair<int, long long>> s;
		s.push(make_pair(-1, 0));
		int curHeight,beHeight,beIdx;	// 현재 높이, 이전 높이, 이전 index
		
		cin >> cases;
		if (cases == 0)//case 입력이 0이면 종료
			break;
		int i;
		for (i = 0;i < cases;i++)
		{
			cin >> curHeight;
			if (s.empty() || s.top().second <= curHeight)
			{
				s.push(make_pair(i, curHeight));
			}
			else 
			{
				while (!s.empty() && s.top().second > curHeight)
				{
					beIdx = s.top().first;
					ans = max((i - beIdx) * s.top().second, ans);
					s.pop();
				}
				s.push(make_pair(beIdx, curHeight));
			}
		}
		while (!s.empty())
		{
			beIdx = s.top().first;
			ans = max((i - beIdx) * s.top().second, ans);
			s.pop();
		}
		cout << ans << "\n";
	}
	

}