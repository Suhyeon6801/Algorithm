#include <iostream>
using namespace std;

int N;
int arr[150][150];
int white = 0, blue = 0;

void Cut(int sx, int sy, int ex, int ey)
{
	int w = 0, b = 0;

	for (int i = sy; i <=ey ; i++)
	{
		for (int j = sx; j <= ex; j++)
		{
			if (arr[i][j] == 0)
				w++;
			else
				b++;
		}
	}

	if (w == 0)
	{
		blue++;
		return;
	}

	if (b == 0)
	{
		white++;
		return;
	}

	Cut(sx, sy, (sx + ex) / 2, (sy + ey) / 2);//1
	Cut((sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2);//2
	Cut(sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey);//3
	Cut((sx + ex) / 2 + 1, (sy + ey) / 2 + 1, ex, ey);//4
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	Cut(0, 0, N - 1, N - 1);

	cout << white << "\n" << blue << "\n";

	return 0;
}