#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 60;
int N;
char board[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int check()
{
	//<-, ->
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		int cnt = 1;
		for (int j = 1; j < N; j++)
		{
			if (board[i][j - 1] == board[i][j])
				cnt++;
			else
			{
				ret = max(ret, cnt);
				cnt = 1;
			}
		}

		ret = max(ret, cnt);
	}
	//△,▽
	for (int i = 0; i < N; i++)
	{
		int cnt = 1; 
		for (int j = 1; j < N; j++)
		{
			if (board[j][i] == board[j - 1][i])
				cnt++;
			else
			{
				ret = max(ret, cnt);
				cnt = 1;
			}
		}
		ret = max(ret, cnt);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	//행,열 한줄로만 쭉 먹을 수 있는 경우 세기.
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			//<-, ->
			swap(board[i][j], board[i][j + 1]);
			result=max(result,check());
			swap(board[i][j], board[i][j + 1]);
			//△,▽
			swap(board[j][i], board[j+1][i]);
			result = max(result, check());
			swap(board[j][i], board[j + 1][i]);
		}
	}

	cout << result << "\n";
	
	return 0;
}