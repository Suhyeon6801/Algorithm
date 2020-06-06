#include <iostream>
#include <string>
using namespace std;

struct Command {
	string cmd;
	string alpha;
	int cur_time;
	int back_time;
};

Command command[110];
bool check[110];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	//**제일 마지막에 실행하는 undo기준으로 명령어를 실행하지 않을 것을 선택하자.

	int N;
	string s, alpha;
	int cur_time, back_time;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (s == "type")
		{
			command[i].cmd = s;
			cin >> command[i].alpha >> command[i].cur_time;
		}
		else
		{
			command[i].cmd = s;
			cin >> command[i].back_time >> command[i].cur_time;
		}
	}

	//undo미리 제거.
	for (int i = N - 1; i >= 0; i--)
	{
		if (check[i])	continue;
		if (command[i].cmd == "type")	continue;

		check[i] = true;

		int temp = command[i].cur_time - command[i].back_time;
		for (int j = i - 1; j >= 0; j--)
		{
			if (temp > command[j].cur_time)	break;
			check[j] = true;
		}
	}

	//type명령어만 남아서 그거 쫙 붙이기.
	string answer = "";
	for (int i = 0; i < N; i++)
	{
		if (!check[i])
			answer += command[i].alpha;
	}
	cout << answer << "\n";

	
	return 0;
}