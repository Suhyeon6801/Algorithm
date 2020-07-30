#include <iostream>
using namespace std;

const int MAX = 1010;
char map[MAX][MAX];
int dpJ[MAX][MAX];//(1,1)에서 (i,j)까지 존재하는 J의 수
int dpO[MAX][MAX];
int dpI[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, K, a, b, c, d;
	cin >> M >> N >> K;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'J')
			{
				dpJ[i][j] = dpJ[i][j - 1] + dpJ[i - 1][j] - dpJ[i - 1][j - 1] + 1;
				dpO[i][j] = dpO[i][j - 1] + dpO[i - 1][j] - dpO[i - 1][j - 1];
				dpI[i][j] = dpI[i][j - 1] + dpI[i - 1][j] - dpI[i - 1][j - 1];
			}
			else if (map[i][j] == 'I')
			{
				dpJ[i][j] = dpJ[i][j - 1] + dpJ[i - 1][j] - dpJ[i - 1][j - 1];
				dpO[i][j] = dpO[i][j - 1] + dpO[i - 1][j] - dpO[i - 1][j - 1];
				dpI[i][j] = dpI[i][j - 1] + dpI[i - 1][j] - dpI[i - 1][j - 1] + 1;
			}
			else if (map[i][j] == 'O')
			{
				dpJ[i][j] = dpJ[i][j - 1] + dpJ[i - 1][j] - dpJ[i - 1][j - 1];
				dpO[i][j] = dpO[i][j - 1] + dpO[i - 1][j] - dpO[i - 1][j - 1] + 1;
				dpI[i][j] = dpI[i][j - 1] + dpI[i - 1][j] - dpI[i - 1][j - 1];
			}
			
		}
	}


	while (K--)
	{
		int jungle = 0, ocean = 0, ice = 0;
		cin >> a >> b >> c >> d;
	
		jungle = dpJ[c][d] - dpJ[c][b - 1] - dpJ[a - 1][d] + dpJ[a - 1][b - 1];
		ocean = dpO[c][d] - dpO[c][b - 1] - dpO[a - 1][d] + dpO[a - 1][b - 1];
		ice= dpI[c][d] - dpI[c][b - 1] - dpI[a - 1][d] + dpI[a - 1][b - 1];

		cout << jungle << " " << ocean << " " << ice << "\n";
	}
	
	return 0;
}