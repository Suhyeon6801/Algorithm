#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> participant;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string name;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> name;
		participant[name]++;
	}

	for (int i = 0; i < N - 1; i++)
	{
		cin >> name;

		participant[name]--;
	}

	for (auto it = participant.begin(); it != participant.end(); it++)
	{
		if (it->second >= 1)
			cout << it->first << "\n";
	}

	return 0;
}