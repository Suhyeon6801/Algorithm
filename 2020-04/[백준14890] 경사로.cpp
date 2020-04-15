#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 110;
int N, L;
int col[MAX][MAX];
int row[MAX][MAX];

bool isPossible(int arr[MAX][MAX], int y, int x)//경사로 설치 가능여부
{
	int temp = arr[y][x + 1];
	for (int i = x + 1; i < x + 1 + L; i++)
	{
		if (temp != arr[y][i])
			return false;
	}
	
	return true;
}

int getRoad(int arr[MAX][MAX])
{
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		bool flag = true;
		int road = 1;
		//모든 칸의 높이가 같을 때
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[i][j] == arr[i][j + 1])
			{
				road++;
			}
			else if (arr[i][j] == arr[i][j + 1] + 1)//내리막길
			{
				if (isPossible(arr, i, j))
				{
					j = j + L - 1;//경사로 설치해주고 이동
					road = 0;
				}
				else
				{
					flag = false;
					break;
				}
			}
			else if (arr[i][j] + 1 == arr[i][j + 1])//오르막길
			{
				if (road >= L)
				{
					road = 1;
				}
				else
				{
					flag = false;
					break;
				}
			}
			else if (abs(arr[i][j] - arr[i][j + 1]) >= 2)//경사로 설치 아예안됨.
			{
				flag = false;
				break;
			}
		}

		if (flag)
			cnt++;
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> col[i][j];
			row[j][i] = col[i][j];
		}
	}

	int c = getRoad(col);
	int r = getRoad(row);

	cout << c + r << "\n";

	return 0;
}