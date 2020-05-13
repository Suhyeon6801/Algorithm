#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> result;

vector<int> makeTable(string p)
{
	vector<int> fail(p.size(), 0);
	int j = 0;
	for (int i = 1; i < p.length(); i++)
	{
		//현재 글자가 일치 하지 않으면 fail값을 계속 따라간다.
		while (j > 0 && p[i] != p[j])
		{
			j = fail[j - 1];
		}

		//일치 하는 경우 현재 j위치에 1을 더한 값이 fail테이블에 들어가면 됨.
		if (p[i] == p[j])
			fail[i] = ++j;
	}

	return fail;
}

void KMP(string parent, string pattern)
{
	vector<int> fail = makeTable(pattern);
	int j = 0;
	int N = parent.size();
	int M = pattern.size();

	for (int i = 0; i < N; i++)
	{
		while (j > 0 && parent[i] != pattern[j])
		{
			j = fail[j - 1];
		}

		if (parent[i] == pattern[j])
		{
			if (j == M - 1)
			{
				result.push_back(i - M + 2);
				j = fail[j];
			}
			else
				j++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string T, P;
	getline(cin, T);
	getline(cin, P);

	KMP(T, P);
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	
	return 0;
}