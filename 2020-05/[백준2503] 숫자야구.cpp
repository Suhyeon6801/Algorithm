#include <iostream>
using namespace std;

int num[1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 123; i <= 987; i++)
		num[i] = i;

	int N;
	int ans, ball, strike;
	int a1, a2, a3, t1, t2, t3;
	int cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> ans >> strike >> ball;

		a1 = ans / 100;
		a2 = (ans / 10) % 10;
		a3 = ans % 10;

		num[ans] = 0;
		cnt = 0;
		for (int j = 123; j <= 987; j++)
		{
			if (num[j] != 0)
			{
				t1 = j / 100;
				t2 = (j / 10) % 10;
				t3 = j % 10;

				int s = 0, b = 0;
				if (t1 != 0 && t2 != 0 && t3 != 0)
				{
					if (t1 != t2 && t2 != t3 && t3 != t1)
					{
						if (t1 == a1)	s++;
						if (t2 == a2)	s++;
						if (t3 == a3)	s++;

						if (t1 == a2 || t1 == a3)	b++;
						if (t2 == a1 || t2 == a3)	b++;
						if (t3 == a1 || t3 == a2)	b++;

						if (s == strike && b == ball)
						{
							cnt++;
						}
						else
							num[j] = 0;
					}
				}
			}
		}
	}

	cout << cnt << "\n";
	
	return 0;
}