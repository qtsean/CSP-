#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int * a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int max = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (abs(a[i] - a[i + 1]) > max)
		{
			max = abs(a[i] - a[i + 1]);
		}
	}
	cout << max;
	system("pause");
	return 0;
}