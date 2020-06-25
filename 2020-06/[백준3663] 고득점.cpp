#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		string name;
		cin >> name;

		int len = name.length();
		int cnt = 0, turn = len - 1;//왼쪽, 오른쪽 어딜루 가야 빠른지

		for (int i = 0; i < len; i++)
		{
			//startTo -> 위(A부터), endTo -> 아래(Z부터)
			int startTo = name[i] - 'A';
			int endTo = 'Z' - name[i] + 1;

			if (startTo < endTo)	cnt += startTo;
			else cnt += endTo;

			int next = i + 1;

			while (next < len&&name[next] == 'A')	next++;

			//초기값, 최대 이동횟수
			//i+len-next : 왼쪽으로 갔을 때 A가 아닌걸 만날때 까지
			//min(i,len-nex) : 현재 진행하는 인덱스와 뒤에서 가장 가까운 A가 아닌 인덱스
			//위에 두 개 중에 작은 거.
			turn = min(turn, i + len - next + min(i, len - next));
		}

		cnt += turn;

		cout << cnt << "\n";
	}
	
	return 0;
}