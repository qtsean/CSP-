#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

void sort(int n, int* a)
{
	int flag;
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = n - 1 ; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

int search_odd(int n, int *a)
{
	int mid = n / 2;
	int right = mid + 1;
	int left = mid - 1;
	while (right < n&&left >= 0)
	{
		if (a[mid] == a[left] && a[mid] == a[right])
		{
			left--;
			right++;
			continue;
		}
		if (a[left] == a[right] && a[left] != a[mid])
		{
			return a[mid];
		}
		if ((a[left] == a[mid] && a[right] != a[mid]) || (a[right] == a[mid] && a[left] != a[mid]))
		{
			return -1;
		}
	}
	return a[mid];
}

int search_even(int n, int *a)
{
	int mid = n / 2;
	if (a[mid] != a[mid - 1])
	{
		return -1;
	}
	else
	{
		int right = mid + 1;
		int left = mid - 2;
		while (right < n &&left >= 0)
		{
			if (a[right] == a[left] && a[right] == a[mid])
			{
				right++;
				left--;
				continue;
			}
			if (a[right] == a[left] && a[right] != a[mid])
			{
				return a[mid];
			}
			if (a[mid] != a[right] && a[mid] != a[left])
			{
				return a[mid];
			}
			if ((a[left] == a[mid] && a[right] != a[mid]) || (a[right] == a[mid] && a[left] != a[mid]))
			{
				return -1;
			}
		}
		return a[mid];
	}
}

int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
//	sort(n, a);
	sort(a, a + n);

	if (n % 2 == 0)
	{
		cout<<search_even(n, a);
	}
	else
	{
		cout << search_odd(n, a);
	}
//	system("pause");
	return 0;
}