#include <iostream>
#include <string>
using namespace std;

int dy[9] = {0,0,0,1,-1,-1,-1,1,1 };
int dx[9] = { 0,1,-1,0,0,1,-1,1,-1 };

bool check(int y, int x)
{
	if (y < 0 || x < 0 || x >= 8 || y >= 8)	return false;
	
	return true;
}

int rotate(string cmd)
{
	if (cmd == "R")	return 1;
	else if (cmd == "L")	return 2;
	else if (cmd == "B")	return 3;
	else if (cmd == "T")	return 4;
	else if (cmd == "RT")	return 5;
	else if (cmd == "LT")	return 6;
	else if (cmd == "RB")	return 7;
	else	return 8;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string king, doll, cmd;
	int N;
	cin >> king >> doll >> N;


	int king_x = king[0] - 'A', king_y = (8 - (king[1] - '0'));
	int doll_x = doll[0] - 'A', doll_y = (8 - (doll[1] - '0'));

	int king_ny, king_nx, doll_ny, doll_nx;

	for (int i = 0; i < N; i++)
	{
		cin >> cmd;

		int dir = rotate(cmd);

		king_ny = king_y + dy[dir];
		king_nx = king_x + dx[dir];
		

		if (!check(king_ny, king_nx))	continue;
		if(king_ny==doll_y&&king_nx==doll_x)
		{
			doll_ny = doll_y + dy[dir];
			doll_nx = doll_x + dx[dir];
			if (!check(doll_ny, doll_nx))	continue;
			doll_y = doll_ny, doll_x = doll_nx;
		}
		king_y = king_ny, king_x = king_nx;
	}

	char kingX = king_x + 'A', dollX = doll_x + 'A';
	int kingY = 8 - king_y, dollY = 8 - doll_y;
	cout << kingX << kingY << "\n";
	cout << dollX << dollY << "\n";

	return 0;
}