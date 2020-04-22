#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 100010;
int N;
int p[MAX];

struct Pos {
	int x, y, z, idx;
};
Pos pos[MAX];

vector<pair<int, pair<int, int>>> edge;

int getCost(Pos p1, Pos p2)
{
	return min(abs(p1.x - p2.x), min(abs(p1.y - p2.y), abs(p1.z - p2.z)));
}

bool compX(Pos p1, Pos p2)
{
	return p1.x < p2.x;
}

bool compY(Pos p1, Pos p2)
{
	return p1.y < p2.y;
}

bool compZ(Pos p1, Pos p2)
{
	return p1.z < p2.z;
}

int find(int x)
{
	if (x == p[x])
		return x;
	else
		return p[x] = find(p[x]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);

	p[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> pos[i].x >> pos[i].y >> pos[i].z;
		pos[i].idx = i;
	}

	sort(pos, pos + N, compX);

	for (int i = 0; i < N - 1; i++)
	{
		int cost = getCost(pos[i], pos[i + 1]);
		edge.push_back(make_pair(cost, make_pair(pos[i].idx, pos[i + 1].idx)));
	}

	sort(pos, pos + N, compY);
	for (int i = 0; i < N - 1; i++)
	{
		int cost = getCost(pos[i], pos[i + 1]);
		edge.push_back(make_pair(cost, make_pair(pos[i].idx, pos[i + 1].idx)));
	}

	sort(pos, pos + N, compZ);
	for (int i = 0; i < N - 1; i++)
	{
		int cost = getCost(pos[i], pos[i + 1]);
		edge.push_back(make_pair(cost, make_pair(pos[i].idx, pos[i + 1].idx)));
	}

	for(int i = 0; i < N; i++)
		p[i] = i;

	sort(edge.begin(), edge.end());

	int cnt = 0;
	int answer = 0;

	for (int i = 0; i < edge.size(); i++)
	{
		int from = edge[i].second.first;
		int to = edge[i].second.second;
		if (find(from) != find(to))
		{
			merge(from,to);
			answer += edge[i].first;
			cnt++;

			if (cnt == N - 1)
				break;
		}
	}

	cout << answer << "\n";
	
	return 0;
}