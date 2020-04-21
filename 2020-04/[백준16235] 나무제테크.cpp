#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 110;
int N, M, K;
int map[MAX][MAX];
int A[MAX][MAX];
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
vector<int> tree[MAX][MAX];
vector<int> dead_tree[MAX][MAX];

void Spring()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int tree_cnt = tree[i][j].size();
			if (tree_cnt == 0)	continue;

			vector<int> temp;//임시 저장소
			sort(tree[i][j].begin(), tree[i][j].end());

			for (int k = 0; k < tree_cnt; k++)
			{
				int myAge = tree[i][j][k];

				if (map[i][j]>=myAge)
				{
					map[i][j] -= myAge;
					temp.push_back(myAge + 1);
				}
				else
				{
					dead_tree[i][j].push_back(myAge);
				}
			}

			tree[i][j].clear();
			for (int k = 0; k < temp.size(); k++)
				tree[i][j].push_back(temp[k]);
		}
	}
}

void Summer()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dead_tree[i][j].size() == 0)	continue;

			for (int k = 0; k < dead_tree[i][j].size(); k++)
			{
				int nori = dead_tree[i][j][k] / 2;
				map[i][j] += nori;
			}
			dead_tree[i][j].clear();
		}
	}
}

void Fall()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (tree[i][j].size() == 0)	continue;

			for (int k = 0; k < tree[i][j].size(); k++)
			{
				int myAge = tree[i][j][k];

				if (myAge % 5 == 0)
				{
					for (int l = 0; l < 8; l++)
					{
						int nx = i + dx[l];
						int ny = j + dy[l];

						if (nx<1 || ny<1 || ny>N || nx>N)	continue;

						tree[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}

void Winter()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			map[i][j] += A[i][j];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	//처음 초기화
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			map[i][j] = 5;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];

	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}

	for(int i=0; i<K; i++)
	{
		Spring();
		Summer();
		Fall();
		Winter();
	}

	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if(tree[i][j].size()>0)
				cnt += tree[i][j].size();
		}
	}

	cout << cnt << "\n";

	return 0;
}