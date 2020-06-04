#include <iostream>
#include <string>
#include <deque>
using namespace std;

const int MAX = 500010;
int arr[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	string str;

	cin >> N >> K;
	cin >> str;

	deque<char> dq;
	for (int i = 0; i < str.length(); i++)
	{
		while (K && !dq.empty() && dq.back()<str[i])
		{
			dq.pop_back();
			K--;
		}
		dq.push_back(str[i]);
	}

	for (int i = 0; i < dq.size() - K; i++)
		cout << dq[i];

	return 0;
}