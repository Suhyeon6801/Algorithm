#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100010;
struct Score {
	int document, interview;
};
Score score[MAX];

bool comp(Score s1, Score s2)
{
	if (s1.document < s2.document)
		return true;
	else if (s1.document == s2.document)
		return s1.interview < s2.interview;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		memset(score, 0, sizeof(score));
		int N;
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> score[i].document >> score[i].interview;

		sort(score, score + N, comp);

		int cnt = 1;
		int grade = score[0].interview;
		for (int i = 1; i < N; i++)
		{
			if (score[i].interview < grade)
			{
				cnt++;
				grade = score[i].interview;
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}