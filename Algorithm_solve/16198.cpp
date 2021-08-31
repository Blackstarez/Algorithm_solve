#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> v,int energy,int visit)
{
	if (v.size() <= 2)
		return energy;
	if (visit != 0)
	{
		energy += v[visit - 1] * v[visit + 1];
		v.erase(v.begin() + visit);
	}
	int maxi = energy, num;
	for (int i = 1;i < v.size() - 1;i++)
	{
		num = solve(v, energy, i);
		if (maxi < num)
			maxi = num;
	}
	return maxi;
}


int main()
{

	vector<int> weight;
	int num;
	cin >> num;
	for (int i = 0;i < num;i++)
	{
		int n;
		cin >> n;
		weight.push_back(n);
	}
	cout << solve(weight, 0, 0);

}