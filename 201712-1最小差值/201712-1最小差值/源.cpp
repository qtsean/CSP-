#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int **b = new int*[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			b[i][j] = abs(a[i] - a[j]);
//			b[j][i] = b[i][j];
		}
	}
	int min = b[0][1];
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (b[i][j] < min)
			{
				min = b[i][j];
			}
		}
	}
	cout << min;
//	system("pause");
	return 0;
}