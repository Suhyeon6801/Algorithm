#include <iostream>
using namespace std;

int dp[2010][2010];//i->j까지가 팰린드롬 이면=1, 아니면 0
int arr[2010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)//초기화
		dp[i][i] = 1;

	int end_idx;
	int tmp = 1;
	for (int i = 1; i <= N - 1; i++)
	{
		end_idx = i + tmp;
		if (arr[i] == arr[end_idx])
			dp[i][end_idx] = 1;
	}

	for (int tmp = 2; tmp <= N; tmp++)
	{
		for (int i = 1; i <= N - tmp; i++)
		{
			end_idx = i + tmp;

			//시작+1, 끝-1이 팰린드롬이고 arr[시작]==arr[끝]->팰린드롬
			if (dp[i + 1][end_idx - 1] == 1 && arr[i] == arr[end_idx])
				dp[i][end_idx] = 1;
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;

		cout << dp[S][E] << "\n";
	}

	
	return 0;
}