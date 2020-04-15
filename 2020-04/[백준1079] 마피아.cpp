#include <iostream>
#include <algorithm>
using namespace std;

int N;
int Eunjin;
int arr[20][20];
int isAlive[20];//1->죽었다, 0->살았다.
int score[20];
int getMax = -1;

int kill_num()
{
	int MaxGuilty = -1;
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		if (MaxGuilty < score[i] && isAlive[i] == 0)
		{			
            MaxGuilty = score[i];
            index = i;
		}
	}

	return index;
}

void dfs(int cur, int day)//남은 인원, 지난밤의 횟수
{
	if (isAlive[Eunjin] == 1 || cur == 1)//기저조건 -> 은진이가 죽거나 남은 사람이 1명일때
	{
		getMax = max(day, getMax);
		return;
	}

	if (cur % 2 == 0)//밤(마피아가 죽인다) -> 순열구하기로 죽일 사람 정해서 죽인다.
	{
		for (int i = 0; i < N; i++)
		{
			if (i == Eunjin || isAlive[i] == 1)	continue;

			isAlive[i] = 1;//죽이고
			for (int j = 0; j < N; j++)//나머지 살아있는 사람 점수 변경
			{
				if (isAlive[j] == 0)
					score[j] += arr[i][j];
			}

			dfs(cur - 1, day + 1);

			for (int j = 0; j < N; j++)
			{
				if (isAlive[j] == 0)
					score[j] -= arr[i][j];
			}
			isAlive[i] = 0;

		}
	}
	else//낮일 경우 -> 살아있는 사람 중 유죄지수 가장 높은 사람 죽이기
	{
		int index = kill_num();

		if (index == Eunjin)//만약 index가 은진이번호면 어차피 죽으니까 결과 return
		{
			getMax = max(day, getMax);
			return;
		}

		isAlive[index] = 1;
		dfs(cur - 1, day);
		isAlive[index] = 0;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> score[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	cin >> Eunjin;

	dfs(N, 0);

	cout << getMax << "\n";

	return 0;
}