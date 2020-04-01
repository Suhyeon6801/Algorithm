#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int arr[30][30];
int N;
bool visit[30];
int getMin = 987654321;

void getValue()
{
	vector<int> startTeam;
	vector<int> linkTeam;
	for (int i = 1; i <=N; i++)
	{
		if (visit[i])
			startTeam.push_back(i);
		else
			linkTeam.push_back(i);
	}

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < startTeam.size(); i++)
	{
		for (int j = 0; j < startTeam.size(); j++)
		{
			if (startTeam[i] != startTeam[j])
				sum1 += arr[startTeam[i]][startTeam[j]];
		}
	}

	for (int i = 0; i < linkTeam.size(); i++)
	{
		for (int j = 0; j < linkTeam.size(); j++)
		{
			if (linkTeam[i] != linkTeam[j])
				sum2 += arr[linkTeam[i]][linkTeam[j]];
		}
	}

	getMin = min(abs(sum1 - sum2), getMin);
}

void f(int cnt, int idx)
{
	if (cnt == N / 2)
	{
		getValue();
		return;
	}

	for (int i = idx; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			f(cnt + 1, i);
			visit[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	f(0, 1);

	cout << getMin << "\n";

	return 0;
}