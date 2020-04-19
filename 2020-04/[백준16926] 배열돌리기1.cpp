#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 310;
int N, M, R;
int arr[MAX][MAX];
int copyArr[MAX][MAX];
int temp[MAX] = { 0, };

void printArr(int a[MAX][MAX])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	int rotate = min(N, M) / 2;//1회전 할 때 돌릴 사각형의 개수

	while (R--)
	{
		for (int k = 0; k < rotate; k++)
		{
			int sy = k, sx = k;
			int ey = N - 1 - k, ex = M - 1 - k;

			int temp = arr[k][k];

			for (int i = sx; i < ex; i++)
				arr[sy][i] = arr[sy][i + 1];

			for (int i = sy; i < ey; i++)
				arr[i][ex] = arr[i + 1][ex];

			for (int i = ex; i > sx; i--)
				arr[ey][i] = arr[ey][i - 1];

			for (int i = ey; i > sy; i--)
				arr[i][sx] = arr[i - 1][sx];

			arr[sy + 1][sx] = temp;
		}
	}

	printArr(arr);

	return 0;
}