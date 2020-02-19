#include <iostream>
#include <cstring>
using namespace std;

int arr[60];
bool visit[60];
int result[60];
int n;

void func(int start, int len)
{
	if (len == 6)
	{
		for (int i = 0; i < len; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = start; i < n; i++)
	{
		result[len] = arr[i];
		func(i + 1, len + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;
	while (1)
	{
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		memset(result, 0, sizeof(result));

		cin >> testcase;

		if (testcase == 0)
			break;

		for (int i = 0; i < testcase; i++)
			cin >> arr[i];

		n = testcase;
		func(0,0);
		cout << "\n";
	}

	return 0;
}