#include <iostream>
using namespace std;

int arr[10];//입력받은 주사위
int yut[4];//현재 말의 위치
int map[40];//윷놀이 판
int turn[40];//방향전환되는 노드
int score[40];//점수판
bool check[40];//해당노드에 말이 있는지 확인
int answer = 0;

void init()
{
	//맵 초기화
	for (int i = 0; i < 21; i++)
		map[i] = i + 1;
	map[21] = 21;

	for (int i = 22; i < 27; i++)
		map[i] = i + 1;
	map[28] = 29; map[29] = 30; map[30] = 25;
	map[31] = 32; map[32] = 25; map[27] = 20;

	turn[5] = 22; turn[10] = 31; turn[15] = 28;

	for (int i = 0; i < 21; i++)
		score[i] = i * 2;
	score[22] = 13; score[23] = 16; score[24] = 19;
	score[31] = 22; score[32] = 24; score[28] = 28;
	score[29] = 27; score[30] = 26; score[25] = 25;
	score[26] = 30; score[27] = 35;
}

void dfs(int cnt, int sum)
{
	if (cnt == 10)
	{
		if (answer < sum)
			answer = sum;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int cur = yut[i];//현재 말 위치
		int next = cur;//이동할 말 위치

		int move = arr[cnt];//움직일 횟수

		if (turn[cur] > 0)//현 위치가 방향전환해야할 곳이라면
		{
			next = turn[cur];//turn배열로 위치 전환
			move -= 1;//한칸 움직였으니까 move-1
		}

		while (move--)//주사위 만큼 이동.
			next = map[next];

		if (next != 21 && check[next])	continue;

		check[cur] = false;
		check[next] = true;
		yut[i] = next;

		dfs(cnt + 1, sum+score[next]);

		yut[i] = cur;
		check[next] = false;
		check[cur] = true;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	for (int i = 0; i < 10; i++)
		cin >> arr[i];

	dfs(0,0);

	cout<<answer<<"\n";

	return 0;
}