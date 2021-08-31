#include <iostream>
using namespace std;

int** matrix;
int matSize;

void resetMatrix()
{
	for (int i = 0;i < matSize;i++)
	{
		for (int j = 0;j < matSize;j++)
		{
			matrix[i][j] =0;
		}
	}
}

void printMatrix()
{
	for (int i = 0;i < matSize;i++)
	{
		for (int j = 0;j < matSize;j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int a, b,c;
	cin >> a >> c;
	matSize = a+1;
	matrix = new int*[a+1];
	for (int i = 0;i <= a;i++)
	{
		matrix[i] = new int[a + 1];
	}

	resetMatrix();

	for (int i = 0;i < c;i++)
	{
		cin >> a >> b;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}

	printMatrix();
}