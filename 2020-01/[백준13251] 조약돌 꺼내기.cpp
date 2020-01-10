#include <cstdio>
using namespace std;

const int MAX = 2501;
double dp[MAX][MAX];
int color[50];

void Pascal() {

	dp[0][0] = dp[1][0] = dp[1][1] = 1;

	for (int i = 2; i < MAX; i++)
	{
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
}

int main()
{
	Pascal();

	int m, k;
	double sum2, base;
	scanf("%d", &m);
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &color[i]);
		sum += color[i];
	}

	scanf("%d", &k);

	sum2 = 0;
	for (int i = 0; i < m; i++)
	{
		sum2 += dp[color[i]][k];
	}

	base = dp[sum][k];

	printf("%.18lf\n", sum2 / base);

	return 0;
}