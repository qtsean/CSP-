#include<iostream>
#include<cstdlib>
using namespace std;

int get_position(int n, int* stu, int num)
{
	for (int i = 0; i < n; i++)
	{
		if (stu[i] == num)
		{
			return i;
		}
	}
}

void change(int n, int* stu, int num, int move)
{
	num = get_position(n, stu, num);
	if (move > 0)
	{
		for (int i = 0; i < move; i++)
		{
			swap(stu[num], stu[num + 1]);
			num++;
		}
	}
	if (move < 0)
	{
		for (int i = 0; i < abs(move); i++)
		{
			swap(stu[num], stu[num - 1]);
			num--;
		}
	}
}



int main()
{
	int n;
	cin >> n;
	int time;
	cin >> time;

	int **a = new int*[time];
	for (int i = 0; i < time; i++)
	{
		a[i] = new int[2];
	}
	for (int i = 0; i < time; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> a[i][j];
		}
	}
	
	/*for (int i = 0; i < time; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/

	int *stu = new int[n];
	for (int i = 0; i < n; i++)
	{
		stu[i] = i + 1;
	}
	for (int i = 0; i < time; i++)
	{
		change(n, stu, a[i][0], a[i][1]);
		/*for (int i = 0; i < n; i++)
		{
			cout << stu[i] << " ";
		}*/
//		cout << endl;
	}
//	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << stu[i] << " ";
	}
//	system("pause");
	return 0;
}