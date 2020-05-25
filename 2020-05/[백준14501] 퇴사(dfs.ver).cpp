#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20;
int Ti[MAX];
int Pi[MAX];
int N;
int result = -1;

void dfs(int now, int sum, int add)
{
	if (now == N + 1)//N+1 되는 날 최댓값 갱싱
	{
		result = max(result, sum);
		return;
	}
	else if (now > N + 1)//N+1이 넘어가면 이전에는 더한거 빼주기!
	{
		result = max(result, sum - add);
		return;
	}

	for (int i = now; i <= N; i++)
		dfs(i + Ti[i], sum + Pi[i], Pi[i]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Ti[i] >> Pi[i];

	dfs(1, 0, 0);

	cout << result << "\n";

	return 0;
}