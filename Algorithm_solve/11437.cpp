#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
	Node* parent;
	int depth;
	int data;
	void setParent(Node* p)
	{
		parent = p;
	}
};


Node nodeList[50001];
vector<int> v[50001];
int visit[50001];

void makeTree()
{
	queue<int> q;
	q.push(1);
	visit[1] = 1;
	nodeList[1].parent = &nodeList[1];
	nodeList[1].data = 1;
	nodeList[1].depth = 1;
	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		for (int i = 0; i < v[num].size(); i++)
		{
			int n = v[num][i];
			if (!visit[n])
			{
				nodeList[n].parent = &nodeList[num];
				nodeList[n].depth = nodeList[num].depth + 1;
				nodeList[n].data = n;
				visit[n] = 1;
				q.push(n);
			}
		}
	}
}

Node* moveToDepth(Node* n, int depth)
{
	Node* tmp = n;
	while (tmp->depth != depth)
	{
		tmp = tmp->parent;
	}
	return tmp;
}

int LCA(int a, int b)
{
	Node* a1, * b1;
	a1 = &nodeList[a];
	b1 = &nodeList[b];

	while (a1->depth != b1->depth)
	{
		if (a1->depth > b1->depth)
			a1 = moveToDepth(a1, b1->depth);
		else
			b1 = moveToDepth(b1, a1->depth);
	}
	while (a1 != b1)
	{
		a1 = moveToDepth(a1, a1->depth - 1);
		b1 = moveToDepth(b1, b1->depth - 1);
	}
	return a1->data;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int num, edge1, edge2;
	cin >> num;
	for (int i = 1; i < num; i++)
	{
		cin >> edge1 >> edge2;
		v[edge1].push_back(edge2);
		v[edge2].push_back(edge1);
	}

	makeTree();

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> edge1 >> edge2;
		cout << LCA(edge1, edge2) << "\n";
	}
}
