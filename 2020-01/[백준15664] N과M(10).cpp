#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int result[10];
bool visit[10010];
int n, m;

void f(int x)
{
	bool visit2[10010] = { 0, };//재귀 반복시 마다 사용한 숫자 중복 검사
	if (x == m)
	{
		for (int i = 0; i < x -1; i++)
		{
			if (result[i] > result[i + 1])
				return;
		}

		for (int i = 0; i < x; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visit2[arr[i]] && !visit[i])
		{
			visit[i] = true;
			visit2[arr[i]] = true;
			result[x] = arr[i];
			f(x + 1);
			visit[i] = false;
			result[x] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	f(0);

	return 0;
}