#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct Edge {
	int from, to;
	double cost;
};

Edge make_node(int a, int b, double c)
{
	Edge temp;
	temp.from = a;
	temp.to = b;
	temp.cost = c;
	return temp;
}

int n;
vector<pair<double, double>> pos;
vector<Edge> edge;
int p[110];

bool comp(Edge e1, Edge e2)
{
	return e1.cost < e2.cost;
}

double getDist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
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
	int pa = find(a);
	int pb = find(b);

	p[pb] = pa;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double x, y;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		pos.push_back({ x,y });
	}

	for (int i = 0; i < pos.size(); i++)
	{
		double x = pos[i].first;
		double y = pos[i].second;

		for (int j = i + 1; j < pos.size(); j++)
		{
			double xx = pos[j].first;
			double yy = pos[j].second;

			double dist = getDist(x, y, xx, yy);

			edge.push_back(make_node(i, j, dist));
		}
	}

	for (int i = 0; i < n; i++)
		p[i] = i;

	sort(edge.begin(), edge.end(), comp);

	double answer = 0;
	int cnt = 0;
	for (int i = 0; i < edge.size(); i++)
	{
		if (find(edge[i].from) != find(edge[i].to))
		{
			merge(edge[i].from, edge[i].to);
			answer += edge[i].cost;
			cnt++;

			if (cnt == n - 1)
				break;
		}
	}

	cout.precision(3);
	cout << answer << "\n";

	return 0;
}