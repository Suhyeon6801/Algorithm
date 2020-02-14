#include <iostream>
#include <algorithm>
using namespace std;

struct Time {
	int start, end;
};

Time time[100010];

bool comp(Time t1, Time t2)
{
	if (t1.end < t2.end)
		return true;
	else if (t1.end == t2.end)
		return t1.start < t2.start;
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
		cin >> time[i].start >> time[i].end;

	sort(time, time + N, comp);

	int room = 0;
	int end = -1;
	for (int i = 0; i < N; i++)
	{
		if (time[i].start >= end)
		{
			end = time[i].end;
			room++;
		}
	}

	cout << room;
	
	return 0;
}