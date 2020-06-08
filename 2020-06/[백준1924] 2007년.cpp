#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	string whatDays[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int x, y;
	int days = 0;
	cin >> x >> y;
	
	days += y;

	for (int i = 1; i < x; i++)
		days += months[i];

	cout << whatDays[days%7] << "\n";


	return 0;
}