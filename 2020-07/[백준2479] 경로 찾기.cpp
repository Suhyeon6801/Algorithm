#include <iostream>
#include <string>
using namespace std;

int N, K, A, B;
string code[1010];
bool adj[1010][1010];//인접행렬로 해밍표현
bool visited[1010];
bool flag = false;
string result = "";

void dfs(int num, string ret)
{
	if (num == B)
	{
		result = ret;
		flag = true;
		return;
	}

	visited[num] = true;

	for (int i = 0; i < N; i++)
	{
		if (i != num)
		{
			if (adj[i][num] && !visited[i])
			{
				//ret += " " + to_string(i+1);
				dfs(i, ret+" "+to_string(i+1));
			}
		}
	}
}

bool isHaming(string s1, string s2)
{
	int cnt = 0;
	for (int i = 0; i < K; i++)
	{
		if (s1[i] != s2[i])	cnt++;
	}

	if (cnt == 1)	return true;
	else	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> code[i];

	cin >> A >> B;

	A--, B--;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (isHaming(code[i], code[j]))
			{
				adj[i][j] = true;
				adj[j][i] = true;
			}
		}
	}

	dfs(A, to_string(A+1));

	if (!flag)	cout << "-1\n";
	else
		cout << result << "\n";

	return 0;
}