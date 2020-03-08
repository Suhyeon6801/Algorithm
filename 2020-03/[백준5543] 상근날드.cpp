#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sang, jung, ha, coke, soda;
	int burger, drink;
	cin >> sang >> jung >> ha >> coke >> soda;

	burger = min(sang, min(jung, ha));
	drink = min(coke, soda);

	cout << burger + drink - 50;
	

	return 0;
}