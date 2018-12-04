#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	int *cake = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> cake[i];
	}
	int child = 0;
	int current = 0;
	int count = 0;
	while (count < n)
	{
		current += cake[count];
		count++;
		if (current >= k || count == n)
		{
			current = 0;
			child++;
		}
	}
	cout << child;
//	system("pause");
	return 0;
}