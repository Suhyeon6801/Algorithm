#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> v;
	string S, temp = "";
	cin >> S;

	for (int i = 0; i < S.length(); i++)
	{
		temp = "";
		for (int j = i; j < S.length(); j++)
		{
			temp += S[j];
		}
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (auto i : v)
		cout << i << "\n";

	return 0;
}