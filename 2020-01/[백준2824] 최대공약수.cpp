#include <cstdio>
#include <string>
using namespace std;

const int MAX = 1010;
int arr[MAX];
int arr2[MAX];

long long gcd(int x, int y)
{
	if (y == 0)
		return x;

	return gcd(y, x%y);
}

int main()
{
	int n, m;
	long long result = 1;
	bool flag = false;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)//n개 약수 저장
		scanf("%d", &arr[i]);

	scanf("%d", &m);
	for (int i = 0; i < m; i++)//m개 약수 받으면서
	{
		scanf("%d", &arr2[i]);

		for (int j = 0; j < n; j++)
		{
			if (arr2[i] == 1)	break;
			if (arr[j] == 1)	continue;

			int k = gcd(arr2[i], arr[j]);//a의 b의 최대공약수를 구해서 한변수에다 곱해줌
			result *= k;

			//약수를 찾았으니 걔네들은 최대 공약수로 나눠준다.
			arr2[i] /= k;
			arr[j] /= k;

			if (result >= 1000000000)
			{
				result = result % 1000000000;
				flag = true;
			}
		}
	}

	if (flag)
	{
		printf("%09lld\n", result);
	}
	else
		printf("%lld\n", result);

	/*string answer = to_string(result);
	if (result> 1000000000)
	{
		answer = answer.substr(answer.length() - 9);
	}
	else
	{
		cout << answer << endl;
	}*/

	return 0;
}