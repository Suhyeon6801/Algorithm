#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100010;
int arr[MAX];
int dp[5][5][MAX];//i는 왼발, j는 오른발에 있으면서 k번째 스텝까지 처리 했을 떄의 최솟값.
int idx = 0;
int cost[5][5] = {//i->j로 이동할 때 이동별 cost 값
	{0,2,2,2,2},
	{0,0,3,4,3},
	{0,3,0,3,4},
	{0,4,3,0,3},
	{0,3,4,3,0}
};

int func(int p1, int p2, int current)//p1->왼쪽, p2->오른쪽
{
	if (current == idx)//수행 끝!
		return 0;

	if (p1 > p2)	swap(p1, p2);

	int &ret = dp[p1][p2][current];
	if (ret != -1)	return ret;

	if (arr[current] == p1 || arr[current] == p2)//제자리 이동
		ret = func(p1, p2, current + 1) + 1;
	else
	{
		int left = func(arr[current], p2, current + 1) + cost[p1][arr[current]];
		int right = func(p1, arr[current], current + 1) + cost[p2][arr[current]];

		ret = min(left, right);
	}

	return ret;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)	break;
		arr[idx++] = n;
	}

	memset(dp, -1, sizeof(dp));
	cout << func(0,0,0) << "\n";

	return 0;
}