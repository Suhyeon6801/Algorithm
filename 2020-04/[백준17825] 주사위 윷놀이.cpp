//https://yabmoons.tistory.com/303 참고

#include <iostream>
using namespace std;

struct Yut {//윷 정보
	int pos, blue_circle, score;
	bool isFinish;
};

struct State {//현재 움직임에 대한 정보
	int cur, next, start_circle;
	bool select_circle, isFinish;
};

int map[4][30];//점수판
bool visit[4][30];
bool special_point[4][30];//모든 경로가 겹치는 점들
int move_num[4];//경로별 움직일 최대 칸수
int cmd[10];
int answer = -1;

Yut yut[4];

void setting()
{
	move_num[0] = 21; move_num[1] = 13; move_num[2] = 17; move_num[3] = 23;

	special_point[1][9] = special_point[1][10] = special_point[1][11] = special_point[1][12] = true;
	special_point[2][13] = special_point[2][14] = special_point[2][15] = special_point[2][16] = true;
	special_point[3][19] = special_point[3][20] = special_point[3][21] = special_point[3][22] = true;
	special_point[0][1] = special_point[0][2] = special_point[0][3] = special_point[0][4] = special_point[0][5] = special_point[0][20] = true;

	for (int i = 0; i <= 20; i++)
		map[0][i] = i * 2;

	map[1][6] = 13; map[1][7] = 16; map[1][8] = 19; map[1][9] = 25;
	map[1][10] = 30; map[1][11] = 35; map[1][12] = 40;
	map[2][11] = 22; map[2][12] = 24; map[2][13] = 25; map[2][14] = 30;
	map[2][15] = 35; map[2][16] = 40;
	map[3][16] = 28; map[3][17] = 27; map[3][18] = 26; map[3][19] = 25;
	map[3][20] = 30; map[3][21] = 35; map[3][22] = 40;

	for (int i = 1; i <= 5; i++) map[1][i] = map[0][i];
	for (int i = 1; i <= 10; i++) map[2][i] = map[0][i];
	for (int i = 1; i <= 15; i++) map[3][i] = map[0][i];
}

State getState(int idx, int cmd_idx)//현재 움직임으로 변하는 윷의 상태 받아오기
{
	State temp;
	temp.cur = yut[idx].pos;
	temp.next = yut[idx].pos + cmd[cmd_idx];
	temp.start_circle = yut[idx].blue_circle;
	temp.select_circle = false;
	temp.isFinish = false;

	if (temp.start_circle == 0)
	{
		if (temp.cur == 5 || temp.cur == 10 || temp.cur == 15)
		{
			temp.select_circle = true;
			temp.start_circle = temp.cur / 5;
		}
	}

	if (temp.next >= move_num[temp.start_circle])	temp.isFinish = true;

	return temp;
}

bool check_special_point(int circle, int pos)
{
	//특별점에 다른 말이 존재하는지 확인
	if (circle == 0)
	{
		//이동하려는 점이 파란색점에서 시작한 적이 없음.
		if (pos == 20)
		{
			if (visit[1][12] || visit[2][16] || visit[3][22])	return false;
		}
		else
		{
			if (visit[0][pos])	return false;
		}
	}
	else if (circle == 1)
	{
		//현재 윷이 1번 파랑점에서 시작->25,30,35,40(겹치는점)확인해줘야함.
		if (visit[2][pos + 4] || visit[3][pos + 10])	return false;
		if (pos == 12)
		{
			if (visit[0][20])	return false;
		}
	}
	else if (circle == 2)
	{
		if (visit[1][pos - 4] || visit[3][pos + 6])	return false;
		if (pos == 16)
		{
			if (visit[0][20])	return false;
		}
	}
	else if(circle==3)
	{
		if (visit[1][pos - 10] || visit[2][pos - 6])	return false;
		if (pos == 22)
		{
			if (visit[0][20])	return false;
		}
	}

	return true;
}

bool check(State s, int idx)//윷이 움직일 수 있는지 판단
{
	//1. 움직이려는 점이 특별점인지 -> 특별점이면 다른 경로로 가서 해당 좌표에서 체크
	//2. 움직이려는 점에 다른 말이 있는지

	if (special_point[s.start_circle][s.next])
	{
		if (!check_special_point(s.start_circle, s.next))	return false;
	}

	if (visit[s.start_circle][s.next])	return false;

	return true;
}

void Start(State s, int idx, bool isTrue)
{
	//방문체크 해주고, 실제 윷을 옮겨줌
	//isTrue=true면 실행, false면 실행취소

	if (isTrue)
	{
		if (s.isFinish)//움직여서 도착점에 도달했다면
		{
			visit[s.start_circle][s.cur] = false;//이전 좌표 해제
			yut[idx].pos = s.next;
			yut[idx].isFinish = true;
		}
		else//도착하지 않은 경우
		{
			if (s.select_circle)//움직였는데, 파랑원번호인경우
			{
				yut[idx].blue_circle = s.start_circle;
				visit[0][s.cur] = false;
			}
			else
			{
				visit[yut[idx].blue_circle][s.cur] = false;
			}

			visit[yut[idx].blue_circle][s.next] = true;
			yut[idx].pos = s.next;
			yut[idx].score += map[yut[idx].blue_circle][s.next];
		}
	}
	else
	{
		if (s.isFinish)
		{
			visit[s.start_circle][s.cur] = true;
			yut[idx].pos = s.cur;
			yut[idx].isFinish = false;
		}
		else
		{
			if (s.select_circle)
			{
				visit[0][s.cur] = true;
				visit[yut[idx].blue_circle][s.next] = false;
				yut[idx].pos = s.cur;
				yut[idx].score -= map[yut[idx].blue_circle][s.next];
				yut[idx].blue_circle = 0;
			}
			else
			{
				visit[yut[idx].blue_circle][s.cur] = true;
				visit[yut[idx].blue_circle][s.next] = false;
				yut[idx].pos = s.cur;
				yut[idx].score-= map[yut[idx].blue_circle][s.next];
			}
		}
	}
}

void dfs(int cnt)
{
	if (cnt == 10)
	{
		int sum = 0;
		for (int i = 0; i < 4; i++)
			sum += yut[i].score;

		if (answer < sum)
			answer = sum;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (yut[i].isFinish)	continue;
		State state = getState(i, cnt);

		if (!check(state, i))	continue;

		Start(state, i, true);
		dfs(cnt + 1);
		Start(state, i, false);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	setting();
	for (int i = 0; i < 10; i++)
		cin >> cmd[i];

	dfs(0);

	cout << answer << "\n";

	return 0;
}