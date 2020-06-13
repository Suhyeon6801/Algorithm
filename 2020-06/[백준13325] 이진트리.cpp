#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_SIZE = 1 << 21;
int K, treeSize, result;
int weight[MAX_SIZE];

int dfs(int idx)
{
	if (idx*2 >= treeSize)
	{
		result += weight[idx];
		return weight[idx];
	}
	else
	{
		int leftNode = dfs(idx * 2);
		int rightNode = dfs(idx * 2 + 1);
		result += weight[idx] + abs(leftNode - rightNode);
		return weight[idx] + max(leftNode, rightNode);//두 가중치 중 더 큰 쪽으로 바꿔주기.
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;

	treeSize = 1 << K + 1;
	for (int i = 2; i < treeSize; i++)
		cin >> weight[i];

	dfs(1);
	cout << result << "\n";

	return 0;
}