#include<iostream>
#include<cstdlib>

using namespace std;

struct stu 
{
	int num;
	bool in;
};

bool check(int num, int k)
{
	if (num % 10 == k)
	{
		return 0;
	}
	if (num%k == 0)
	{
		return 0;
	}
	return 1;
}

int main()
{
	int n;
	int k;
	
	cin >> n;
	cin >> k;
	int count = n;
	
	stu *a = new stu[n];
	for (int i = 0; i < n; i++)
	{
//		cin >> a[i].num;
		a[i].in = 1;
	}
	int current = 0;
	int current_num = 0;
	while (count > 1)
	{
		if (a[current].in == 0)
		{
			current++;
			current %= n;
			continue;
		}
			

		current_num++;
		a[current].num = current_num;
		if (!check(a[current].num,k))
		{
			a[current].in = 0;
			count--;
		}
		current++;
		current %= n;
	}
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].in == 1)
		{
			index = i;
			break;
		}

	}
	cout << (index + 1);
	return 0;

}