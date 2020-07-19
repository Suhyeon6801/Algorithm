#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 410;
int arr[MAX][MAX];
int n;

void floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j || j == k || k == i)	continue;

				if (arr[i][j]==0)
				{
					if (arr[i][k] == 1 && arr[k][j] == 1)
						arr[i][j] = 1;
					else if (arr[i][k] == -1 && arr[k][j] == -1)
						arr[i][j] = -1;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, s, c1, c2;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> c1 >> c2;
		arr[c1][c2] = -1;
		arr[c2][c1] = 1;
	}

	floyd();

	cin >> s;
	while (s--)
	{
		cin >> c1 >> c2;
		cout << arr[c1][c2] << "\n";
	}
	
	return 0;
}