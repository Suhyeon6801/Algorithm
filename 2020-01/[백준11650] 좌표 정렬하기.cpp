#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100010;
struct Point {
	int x;
	int y;
};

Point p[MAX];

bool comp(Point p1, Point p2)
{
	if (p1.x < p2.x)	return true;
	else if(p1.x==p2.x)
	{
		return p1.y < p2.y;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x >> p[i].y;
	}

	sort(p, p + n, comp);

	for (int i = 0; i < n; i++)
	{
		cout << p[i].x << " " << p[i].y << "\n";
	}
	
	return 0;
}[]