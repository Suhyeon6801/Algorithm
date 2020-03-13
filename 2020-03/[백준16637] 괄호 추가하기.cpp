#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 99999999999999999;
int N;
int number[100];
char oper[100];
int getMax = -INF;

int calc(int a, int b, char o)
{
	if (o == '+')	return a + b;
	else if (o == '-')	return a - b;
	else if (o == '*') return a * b;
}

void func(int idx, int cur)
{
	if (idx >= N / 2)
	{
		getMax = max(getMax, cur);
		return;
	}

	//현재 연산자 위치 기준으로 괄호 추가
	int next = calc(cur, number[idx + 1], oper[idx]);
	func(idx + 1, next);

	//연산자 추가 하지 않는 경우
	if (idx + 1 < N / 2)
	{
		int next2 = calc(number[idx + 1], number[idx + 2], oper[idx + 1]);
		int next = calc(cur, next2, oper[idx]);
		func(idx + 2, next);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char op;
	int idx = 0, idx2 = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> op;
		if (i % 2 == 0)
			number[idx++] = op - '0';
		else
			oper[idx2++] = op;
	}

	func(0, number[0]);

	cout << getMax << "\n";

	return 0;
}