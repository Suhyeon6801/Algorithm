#include <iostream>
using namespace std;

int N;
int result[100];
int cnt = 0;

bool check(int len)//뒤에서부터 검사, 한번이라도 좋은수열 위반시 false
{
	for (int i = 1; i <= len / 2; i++)
	{
		int val = 0;
		for (int j = len - 1; j > len - 1 - i; j--)
		{
			if (result[j] == result[j - i])
				val++;
		}

		if (val == i)	return false;
	}
	return true;
}

void func(int len)
{
	if (cnt > 0)	return;
	if (!check(len))	return;
	if (len == N)
	{
		cnt++;
		for (int i = 0; i < N; i++)
			cout << result[i];
		cout << "\n";
		return;
	}

	result[len] = 1;
	func(len + 1);

	result[len] = 2;
	func(len + 1);

	result[len] = 3;
	func(len + 1);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	func(0);

	return 0;
}