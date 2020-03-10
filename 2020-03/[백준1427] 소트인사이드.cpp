#include <iostream>
#include <algorithm>
#include <functional>
#include <string.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char N[20];
	cin >> N;

	int len = strlen(N);
	sort(N, N + len, greater<int>());
	cout << N;

	return 0;
}