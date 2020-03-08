#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 32010;
int indegree[MAX];
vector<int> v[MAX];//�׷��� ��������Ʈ �����

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> que;
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		v[a].push_back(b);
		indegree[b]++;//indegree���� ����, ��������
	}

	for (int i = 1; i <= n; i++)//indegree������ 0�̸� queue�� ��´�.
	{
		if (indegree[i] == 0)
			que.push(i);
	}

	while (!que.empty())//que�� �������� 
	{
		int cur = que.front();//���� ���� �̴���.
		que.pop();
		cout << cur << " ";

		for (int i = 0; i < v[cur].size(); i++)//�� ������ ����� �������� indegree�� �ϳ��� ����
		{
			int next = v[cur][i];
			indegree[next]--;
			if (indegree[next] == 0)//indegree�� 0�� �Ǵ� ������ que�� ��´�.
				que.push(next);
		}
	}

	return 0;
}