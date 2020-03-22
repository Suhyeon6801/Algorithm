#include <iostream>
#include <queue>
using namespace std;

struct Icon {
	int screen, clipborad, sec;
};

Icon make_node(int a, int b, int c)
{
	Icon temp;
	temp.screen = a;
	temp.clipborad = b;
	temp.sec = c;

	return temp;
}

bool visit[1010][1010];//화면에 i개, 클립보드에 j개

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int S;
	cin >> S;

	queue<Icon> que;
	que.push(make_node(1, 0, 0));
	visit[1][0] = true;

	while (!que.empty())
	{
		int screen = que.front().screen;
		int clipboard = que.front().clipborad;
		int sec = que.front().sec;
		que.pop();

		if (screen == S)
		{
			cout << sec << "\n";
			return 0;
		}

		//1번
		if (screen > 0 && screen <= 1000 && !visit[screen][screen])
		{
			visit[screen][screen] = true;
			que.push(make_node(screen, screen, sec + 1));
		}

		//2번
		if (clipboard > 0 && screen + clipboard <= 1000 && !visit[screen + clipboard][clipboard])
		{
			visit[screen + clipboard][clipboard] = true;
			que.push(make_node(screen + clipboard, clipboard, sec + 1));
		}

		//3번
		if (screen > 0 && screen <= 1000 && !visit[screen - 1][clipboard])
		{
			visit[screen - 1][clipboard] = true;
			que.push(make_node(screen - 1, clipboard, sec + 1));
		}
	}
	

	return 0;
}