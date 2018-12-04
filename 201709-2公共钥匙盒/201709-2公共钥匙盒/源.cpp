#include<iostream>
#include<cstdlib>

using namespace std;

int end_time(int K, int** a)
{
	int end = 0;
	for (int i = 0; i < K; i++)
	{
		if (a[i][2] > end)
		{
			end = a[i][2];
		}
	}
	return end;
}

void return_key(int time, int K, int N, int** a, int* box)
{
	for (int i = 0; i < K; i++)
	{
		if (time == a[i][2])
		{
			for (int j = 0; j < N; j++)
			{
				if (box[j] == -1)
				{
					box[j] = a[i][0];
					break;
				}
			}
		}
	}
}

void borrow_key(int time, int K, int N, int **a, int *box)
{
	for (int i = 0; i < K; i++)
	{
		if (time == a[i][1])
		{
			for (int j = 0; j < N; j++)
			{
				if (box[j] == a[i][0])
				{
					box[j] = -1;
					break;
				}
			}
		}
	}
}

void show_box(int N, int* box)
{
	for (int i = 0; i < N; i++)
	{
		cout << box[i] << " ";
	}
	cout << endl;
}

void order_by_keyNumber(int K, int **a)
{
	for (int i = 0; i < K; i++)
	{
		for (int j = K - 1; j > 0; j--)
		{
			if (a[j][0] < a[j - 1][0])
			{
				int t1 = a[j][0];
				int t2 = a[j][1];
				int t3 = a[j][2];
				a[j][0] = a[j - 1][0];
				a[j][1] = a[j - 1][1];
				a[j][2] = a[j - 1][2];
				a[j - 1][0] = t1;
				a[j - 1][1] = t2;
				a[j - 1][2] = t3;
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	int K;
	cin >> K;
	int **a = new int*[K];
	for (int i = 0; i < K; i++)
	{
		a[i] = new int[3];
	}
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
		a[i][0] -= 1;
		a[i][2] = a[i][1] + a[i][2];
	}
	order_by_keyNumber(K, a);
	/*for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}*/
	int *box = new int[N];			//³õÊ¼»¯ºĞ×Ó
	for (int i = 0; i < N; i++)
	{
		box[i] = i;
	}
	int endOfTime = end_time(K, a) + 1;
	for (int time = 0; time < endOfTime; time++)
	{
		return_key(time, K, N, a, box);
		borrow_key(time, K, N, a, box);
//		show_box(N, box);
	}
	for (int i = 0; i < N; i++)
	{
		cout << (box[i] + 1) << " ";
	}
//	system("pause");
	return 0;
}