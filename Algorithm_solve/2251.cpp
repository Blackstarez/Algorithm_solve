#include <iostream>
#include <vector>
using namespace std;


int ans[201];
int va, vb, vc;
int volume[3];
int visit[201][201][201] = { {{0,},}, };

void dfs(int a, int b, int c)
{

	if (a == 0)
		ans[c] = 1;
	visit[a][b][c] = 1;

	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			if (i != j)
			{
				int arr[3] = { a, b, c };

				arr[j] += arr[i];
				arr[i] = 0;
				if (arr[j] > volume[j])
				{
					arr[i] = arr[j] - volume[j];
					arr[j] = volume[j];
				}

				if (!visit[arr[0]][arr[1]][arr[2]])
					dfs(arr[0], arr[1], arr[2]);
			}
		}
	}


}

int main()
{
	cin >> va >> vb >> vc;
	volume[0] = va;
	volume[1] = vb;
	volume[2] = vc;
	dfs(0, 0, vc);

	for(int i=0;i<201;i++)
	{
		if (ans[i] == 1)
			cout << i<< " ";
	}
}