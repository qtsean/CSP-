#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	int a[30];
	for (int i = 0; i < 30; i++)
	{
		a[i] = 0;
	}
	for (int i = 0; i < 30; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
		{
			break;
		}
	}
	int step = 0;
	int sum = 0;
	int current_score = 0;
	while (a[step] != 0)
	{
		if (a[0] == 0)
		{
			break;
		}
		if (a[step] != 0)
		{
			if (step == 0)
			{
				if (a[step] == 2) 
				{
					current_score = 2;
					sum += current_score;
				}
				else if (a[step] == 1)
				{
					current_score = 0;
					sum += 1;
				}
			}
			else
			{
				if (a[step] == 1)
				{
					sum += 1;
					current_score = 0;
				}
				else
				{
					current_score += 2;
					sum += current_score;
				}
			}
		}
		else 
		{
			break;
		}
		step++;
	}
	cout << sum;
//	system("pause");
	return 0;
}
