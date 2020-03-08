#include <iostream>
using namespace std;
const int MAX = 1010;
int map[MAX][MAX];
int dp[MAX + 2][MAX + 2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w, n;
	cin >> h >> w >> n;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> map[i][j];
		}
	}

	dp[0][0] = n - 1;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (dp[i][j] == 0)	continue;//������ �ʾҴٸ� ��ŵ
			else
			{
				dp[i + 1][j] += dp[i][j] / 2;//��
				dp[i][j + 1] += dp[i][j] / 2;//��

				if (dp[i][j] % 2 == 1)//Ȧ��
				{
					if (map[i][j] == 1)// ������¿� ���� ��,���� �߰��Ѵ�.
					{
						dp[i][j + 1]++;
					}
					else
						dp[i + 1][j]++;
				}

				map[i][j] = (map[i][j] + dp[i][j]) % 2;//2�� �������� ������ ��ä �������ش�.
			}
		}
	}

	int i = 0, j = 0;
	while (i < h&&j < w)
	{
		if (map[i][j] == 1)	j++;//����������
		else
			i++;//����
	}

	cout << i + 1 << " " << j + 1 << "\n";

	return 0;
}