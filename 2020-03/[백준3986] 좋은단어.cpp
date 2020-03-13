#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isGood(string word)
{
	stack<char> st;

	for (int i = 0; i < word.length(); i++)
	{
		if (st.empty())
		{
			st.push(word[i]);
		}
		else
		{
			if (st.top() == word[i])
				st.pop();
			else
				st.push(word[i]);
		}
	}

	if (st.empty())
		return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		if (isGood(str))
			cnt++;
	}

	cout << cnt << "\n";

	return 0;
}