#include <iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int score;
	cin >> score;

	if (score <= 100 && score >= 90)
		cout << "A\n";
	else if (score >= 80 && score < 90)
		cout << "B\n";
	else if (score >= 70 && score < 80)
		cout << "C\n";
	else if (score >= 60 && score < 70)
		cout << "D\n";
	else
		cout << "F\n";
	

	return 0;
}