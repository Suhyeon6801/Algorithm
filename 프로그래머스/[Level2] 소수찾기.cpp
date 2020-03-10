#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <cstring>
using namespace std;

vector<int> v;
bool visit[10];
int arr[10];
set <int> result;

bool isPrime(int x)//소수인지 검사하는 함수
{
	if (x == 0 || x == 1)	return false;

	for (int i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
			return false;
	}

	return true;
}

void make_number(int len, int x)
{
	if (len == x)
	{
		string str = "";
		for (int i = 0; i < len; i++)
		{
			char c = arr[i] + '0';
			str += c;
		}

		int temp = atoi(str.c_str());
		if (!isPrime(temp))	return;

		result.insert(temp);

		return;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			arr[len] = v[i];
			make_number(len + 1, x);
			visit[i] = false;
			arr[len] = 0;
		}
	}
}

int solution(string numbers) {
	int answer = 0;

	for (int i = 0; i < numbers.length(); i++)
		v.push_back(numbers[i] - '0');

	sort(v.begin(), v.end(), greater<int>());//맨앞에 0이 오지 않게.

	for (int i = 1; i <= numbers.length(); i++)
	{
		memset(visit, 0, sizeof(visit));
		memset(arr, 0, sizeof(arr));

		make_number(0, i);
	}

	answer = result.size();
	return answer;
}