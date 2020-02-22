#include <iostream>
using namespace std;

struct Robot {
	int x, y, dir;
};

struct Command {
	int robot_num;
	char cmd;
	int count;
};

Robot robot[110];
Command command[110];

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,-1,0,1 };
int map[110][110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B;
	int N, M;
	char d;
	cin >> A >> B;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> robot[i].x >> robot[i].y >> d;

		if (d == 'N')
			robot[i].dir = 0;
		else if (d == 'W')
			robot[i].dir = 1;
		else if (d == 'S')
			robot[i].dir = 2;
		else if (d == 'E')
			robot[i].dir = 3;

		map[robot[i].y][robot[i].x] = i;
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> command[i].robot_num >> command[i].cmd >> command[i].count;
	}

	int error = 0;
	int robot1, robot2;

	for (int i = 1; i <= M; i++)
	{
		int curRobot = command[i].robot_num;

		if (command[i].cmd == 'L')//왼쪽으로 90도 회전
		{
			for (int j = 0; j < command[i].count; j++)
			{
				robot[curRobot].dir = (robot[curRobot].dir + 1) % 4;
			}
		}
		else if (command[i].cmd == 'R')//오른쪽으로 90도 회전
		{
			for (int j = 0; j < command[i].count; j++)
			{
				robot[curRobot].dir--;
				if (robot[curRobot].dir < 0)
					robot[curRobot].dir = 3;
			}
		}
		else if (command[i].cmd == 'F')//앞으로 안칸
		{
			int x = robot[curRobot].x;
			int y = robot[curRobot].y;
			int dir = robot[curRobot].dir;
			int ny = 0;
			int nx = 0;

			for (int j = 0; j < command[i].count; j++)
			{
				ny = y + dy[dir];
				nx = x + dx[dir];

				//벽에 충돌
				if (ny <= 0 || nx <= 0 || ny > B || nx > A)
				{
					error = 1;
					robot1 = curRobot;
					break;
				}
				else if (map[ny][nx] != 0)//다른 로봇이랑 부딪힘
				{
					error = 2;
					robot1 = curRobot;
					robot2 = map[ny][nx];
					break;
				}

				if (error != 0)	break;

				//이동
				y = ny;
				x = nx;
			}

			map[robot[curRobot].y][robot[curRobot].x] = 0;
			map[ny][nx] = curRobot;
			robot[curRobot].y = y;
			robot[curRobot].x = x;
		}

		if (error != 0)	break;
	}

	if (error == 0)
		cout << "OK\n";
	else if (error == 1)
		cout << "Robot " << robot1 << " crashes into the wall\n";
	else if (error == 2)
		cout << "Robot " << robot1 << " crashes into robot " << robot2 << "\n";

	return 0;
}