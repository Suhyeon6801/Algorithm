#include <iostream>
#include <algorithm>
using namespace std;

struct Point
{
	int x;
	int y;
};
Point p[100010];

bool comp(Point p1, Point p2)
{
	if (p1.y < p2.y)
		return true;
	else if (p1.y == p2.y)
		return p1.x < p2.x;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> p[i].x >> p[i].y;

	sort(p, p + N, comp);

	for (int i = 0; i < N; i++)
		cout << p[i].x <<" "<< p[i].y << "\n";
	
	return 0;
}