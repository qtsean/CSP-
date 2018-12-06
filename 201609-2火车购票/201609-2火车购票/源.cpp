#include<iostream>
#include<cstdlib>
#include<vector>
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
	vector<int> seat[20];
	vector<int> *ticket = new vector<int>[n];
	for (int i = 0; i < n; i++)
	{
		int count = a[i];
		//ÏÈÕÒÁ¬Ðø
		int found = 0;
		for (int j = 0; j < 20; j++)
		{
			if (count <= 5 - seat[j].size())
			{
				found = 1;
				for (int t = 0; t < count; t++)
				{
					seat[j].push_back(1);
					ticket[i].push_back(j * 5 + seat[j].size());
				}
				break;
			}
		}
		if (found == 0)
		{
			for (int t = 0; t < count; t++)
			{
				for (int j = 0; j < 20; j++)
				{
					if (seat[j].size() < 5)
					{
						seat[j].push_back(1);
						ticket[i].push_back(j * 5 + seat[j].size());
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a[i]; j++)
		{
			cout << ticket[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}