#include <iostream>
#include <vector>
using namespace std;

const int MAX = 110;
int map[MAX][MAX];
int N;
int x, y, d, g;
vector<int> dir;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

void Draw()//드래곤 커브 그리기
{
	int size = dir.size();

	for (int i = size - 1; i >= 0; i--)//역순으로 탐색
	{
		int nd = (dir[i] + 1) % 4;

		x = x + dx[nd];
		y = y + dy[nd];

		map[x][y] = 1;

		dir.push_back(nd);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt = 0;

	cin >> N;

	while(N--)
	{
		dir.clear();

		cin >> x >> y >> d >> g;

		map[x][y] = 1;
		x = x + dx[d];
		y = y + dy[d];
		map[x][y] = 1;

		dir.push_back(d);
		for (int i = 0; i < g; i++)
			Draw();
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] && map[i + 1][j + 1])
				cnt++;
		}
	}

	cout << cnt << "\n";
	
	return 0;
}