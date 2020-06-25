#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string jaehwan, doctor;
	cin >> jaehwan >> doctor;

	if (jaehwan.length() < doctor.length())
		cout << "no\n";
	else
		cout << "go\n";
	
	return 0;
}