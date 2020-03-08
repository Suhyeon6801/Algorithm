#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10010;
vector<int> g[MAX];
int order[MAX];
bool isCut[MAX];
int cnt = 1;

int dfs(int x, bool isRoot)
{
	order[x] = cnt++; // dfs�湮���� ����
	int ret = order[x];

	int child = 0;//�ڽļ� count

	for (int i = 0; i < g[x].size(); i++)
	{
		int next = g[x][i];

		//�̹� Ž���� �����̸� ���� ���� �湮������ Ž���� ������ �湮���� �� �ּڰ�ã��
		//A�� ��ġ�� �ʰ� ���� A���� ���� �湮��ȣ�� ���� �������� �� �� ���ٸ� ������. ���ٸ� �������� �ƴϴ�.

		if (order[next])//�湮�� �̹� ��.
		{
			ret = min(ret, order[next]);
			continue;
		}

		child++;//�ڽİ��� �ϳ� �÷��ְ�(nextŽ�������ϱ�) next�� �Ѿ
		int prev = dfs(next, false);// �� next�� ��Ʈ�� �ƴ϶��
		if (!isRoot&&prev >= order[x])
			isCut[x] = true;

		ret = min(ret, prev);
	}

	if (isRoot)//��Ʈ���, child���� 2�̻��̸� ������.
	{
		if (child >= 2)
			isCut[x] = true;
	}

	return ret;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//����A�� ��Ʈ���, �ڽļ��� 2�� �̻��̸� �������̴�.
	//����A�� ��Ʈ�� �ƴϸ�, A�� ��ġ�� �ʰ� ���� A���� ���� �湮��ȣ�� ���� �������� �� �� ���ٸ� ������. ���ٸ� �������� �ƴϴ�.
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int A, B;
		cin >> A >> B;
		g[A].push_back(B);
		g[B].push_back(A);
	}

	for (int i = 1; i <= V; i++)
	{
		if (!order[i])
			dfs(i, true);
	}

	int count = 0;
	for (int i = 1; i <= V; i++)
	{
		if (isCut[i])	count++;
	}

	cout << count << "\n";
	for (int i = 1; i <= V; i++)
	{
		if (isCut[i])
			cout << i << " ";
	}

	return 0;
}