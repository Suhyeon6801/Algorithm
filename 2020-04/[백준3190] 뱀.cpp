#include <iostream>
#include <deque>
#include <queue>
using namespace std;

struct Pos {
	int y, x;
};
Pos pos[110];
int map[110][110];
bool visit[110][110];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int getDir()
{
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, L;
	int X;
	char C;
	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int y, x;
		cin >> y >> x;

		map[y][x] = 1;
	}

	deque<pair<int, int>> snake;//앞쪽은 머리, 뒤쪽은 꼬리
	snake.push_back(make_pair(1, 1));//초기 위치
	int dir = 0;//초기 방향
	visit[1][1] = true;
	int cnt = 0;

	cin >> L;
	queue<pair<int, char>> que;
	for (int i = 0; i < L; i++)
	{
		cin >> X >> C;
		que.push(make_pair(X, C));
	}

	while (1)
	{
		cnt++;
		pair<int, int> tail = snake.front();
		pair<int, int> head = snake.back();

		int ny = head.first + dy[dir];
		int nx = head.second + dx[dir];

		if (visit[ny][nx] || ny < 1 || nx < 1 || ny > N || nx > N)//머리가 몸에 부딪치거나, 범위를 벗어나면 종료
		{
			cout << cnt << "\n";
			break;
		}
		else
		{
			visit[ny][nx] = true;
			snake.push_back(make_pair(ny, nx));

			if (map[ny][nx] == 1)//사과가 있으면, 사과만 지우고 꼬리는 그대로
			{
				map[ny][nx] = 0;
			}
			else//사과가 없으면 꼬리가 위치한 칸 지워주기
			{
				visit[tail.first][tail.second] = false;
				snake.pop_front();
			}
		}

		if (que.size()!=0 && cnt == que.front().first)//게임 시작 후 X초가 끝나면 방향 전환
		{
			if (que.front().second == 'D')//오른쪽으로 90
				dir = (dir + 1) % 4;
			else
				dir = (dir + 3) % 4;

			que.pop();
		}
	}

	return 0;
}