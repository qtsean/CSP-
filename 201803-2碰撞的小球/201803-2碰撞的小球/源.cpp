#include<iostream>
#include<cstdlib>

using namespace std;

void check_contact(int i, int n, int **location, int* calculated)
{
	if (calculated[i] == 1 || i == n - 1)
	{
		return;
	}
	for (int current = i+1; current < n; current++)
	{
		if (location[i][0] == location[current][0])
		{
			location[i][1] *= -1;
			location[current][1] *= -1;
			calculated[i] = 1;
			calculated[current] = 1;
		}
	}
}

void check_edge(int i, int L, int**location, int*calculated)
{
	if (calculated[i] == 1)
	{
		return;
	}
	if (location[i][0] == 0 || location[i][0] == L )
	{
		location[i][1] *= -1;
		calculated[i] = 1;
	}
}

int main()
{
	int n;
	int L;
	int t;
	cin >> n;
	cin >> L;
	cin >> t;

	int **location = new int*[n];
	for (int i = 0; i < n; i++)
	{
		location[i] = new int[2];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> location[i][0];
		location[i][1] = 1;						//右1左-1
	}
	for (int time = 0; time < t; time++)
	{
		int *calculated = new int[n];
		for (int i = 0; i < n; i++)
		{
			calculated[i] = 0;					//表示还没碰撞过
		}
		for (int i = 0; i < n; i++)
		{
			check_contact(i, n, location, calculated);
			check_edge(i, L, location, calculated);
		}
		for (int i = 0; i < n; i++)
		{
			if (location[i][1] == 1)
			{
				location[i][0]++;
			}
			else
			{
				location[i][0]--;
			}
		}
		delete[]calculated;
	}
	for (int i = 0; i < n; i++)
	{
		cout << location[i][0] << " ";
	}
	return 0;
}