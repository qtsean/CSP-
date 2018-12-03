#include<cstdlib>
#include<iostream>

using namespace std;

bool search(int* a, int* b, int current, int n)
{
	if (current == n - 1)
	{
		if ((b[current] + b[current - 1]) / 2 == a[current])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (current == 0)
	{
		for (int i = 1; i < 100; i++)
		{
			b[current] = i;
			b[current + 1] = 2 * a[current] - b[current];
			if (search(a, b, current + 1, n))
			{
				break;
			}
			
		}
		return true;
	}
	else
	{
		int temp = 3 * a[current] - b[current - 1] - b[current];
		int x = temp;
		if (temp <= 0) 
		{
			for (int i = 0; i < 2; i++)
			{
				temp += 1;
				if (temp > 0)
				{
					break;
				}			
			}
		}
		if (temp <= 0)
		{
			return false;
		}
		else
		{
			int t = temp - 1;
			for (int i = 0; i < 3-(temp -x); i++)
			{
				t++;
				b[current + 1] = t;
				if (search(a, b, current + 1, n))
				{
					return true;
				}
			}
			return false;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	search(a, b, 0, n);
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}
	system("pause");
	return 0;
}