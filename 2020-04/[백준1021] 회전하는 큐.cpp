#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> dq;
	deque<int> temp1;
	deque<int> temp2;
	int N, M, num;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> num;

		if (dq.front() == num)
			dq.pop_front();
		else
		{
			int op1 = 0, op2 = 0;
			temp1 = dq;//덱 복사
			temp2 = dq;

			//앞에서 부터 빼기
			while (!temp1.empty())
			{
				int idx = temp1.front();
				if (idx == num)
				{
					temp1.pop_front();
					break;
				}
				
				temp1.pop_front();
				temp1.push_back(idx);
				op1++;
			}

			//뒤에서 부터 빼기
			while (!temp2.empty())
			{
				if (temp2.front() == num)
				{
					temp2.pop_front();
					break;
				}

				int idx = temp2.back();
				temp2.pop_back();
				temp2.push_front(idx);
				op2++;
			}

			if (op1 < op2)
			{
				dq = temp1;
				cnt += op1;
			}
			else
			{
				dq = temp2;
				cnt += op2;
			}

			temp1.clear();
			temp2.clear();
		}
	}

	cout << cnt << "\n";

	return 0;
}