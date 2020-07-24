#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 500000;
int N, M;
int brokenBtn[20];

int getLen(int cur)
{
	if (cur == 0)
	{
		if (brokenBtn[0])	return 0;
		else	return 1;
	}

	int len = 0;
	while (cur > 0)
	{
		int k = cur % 10;
		if (brokenBtn[k])	return 0;

		cur /= 10;
		len++;
	}

	return len;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cur = 100;
	int button;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> button;
		brokenBtn[button] = true;
	}

	int result = abs(N - cur);

	for (int i = 0; i <= MAX*2; i++)//최댓값 : 이동 위치에서 감소하는 범위도!! -> 넉넉하게 잡자
	{
		int channel = i;
		int len = getLen(channel);

		if (len > 0)
		{
			int cnt = abs(N- channel);
			if (result > cnt + len)
				result = cnt + len;
		}
	}

	cout << result << "\n";

	return 0;
}