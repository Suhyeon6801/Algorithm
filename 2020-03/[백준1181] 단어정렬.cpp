#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<string> words;
map<string, bool> isVisit;

bool comp(string s1, string s2)
{
	if (s1.length() < s2.length())
		return true;
	else if (s1.length() == s2.length())
	{
		return s1.compare(s2) < 0;
	}
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string word;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> word;

		if (!isVisit.count(word))
		{
			words.push_back(word);
			isVisit.insert(make_pair(word, true));
		}
	}

	sort(words.begin(), words.end(), comp);

	for (int i = 0; i < words.size(); i++)
		cout << words[i] << "\n";

	return 0;
}