#include<iostream>
#include<cstdlib>
using namespace std;

bool check_overlap(int** a, int** b, int m, int d)
{
	int overlap = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i + d < 16 && j + m - 1 < 10) 
			{
				if (a[i + d][j + m - 1] == 1 && b[i][j] == 1)
				{
					overlap = 1;
					break;
				}
			}
		}
	}
	return overlap;
}

void merge(int** a, int**b, int m, int d)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if(i+d<16&&j+m-1<10)
				a[i + d][j + m - 1] = b[i][j] || a[i + d][j + m - 1];
		}
	}
}

int main()
{
	int **a = new int*[16];
	for (int i = 0; i < 16; i++)
	{
		a[i] = new int[10];
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int j = 0; j < 10; j++)
	{
		a[15][j] = 1;
	}
	int **b = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		b[i] = new int[4];
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> b[i][j];
		}
	}
	int m;
	cin >> m;				//move
	int d;
	for (d = 0; ; d++)
	{
		if (check_overlap(a, b, m, d))
		{
			d--;
			break;
		}
	}
	merge(a, b, m, d);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}