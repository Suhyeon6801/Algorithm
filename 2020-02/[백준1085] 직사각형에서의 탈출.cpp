#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int dist1, dist2, dist3, dist4;

	dist1 = x;
	dist2 = w - x;
	dist3 = y;
	dist4 = h - y;

	int result = min(dist1, min(dist2, min(dist3, dist4)));
	cout << result << "\n";
	
	return 0;
}