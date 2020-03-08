#include <iostream>
#include <algorithm>
using namespace std;

char alpha[20] = { 0, };
bool check[20] = { 0, };
char result[20] = { 0, };
int L, C;

bool isPossible(char ch[20])
{
	int vowel = 0;
	int consonant = 0;
	for (int i = 0; i < L; i++)
	{
		if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
		{
			vowel++;
		}
		else
		{
			consonant++;
		}
	}

	if (vowel >= 1 && consonant >= 2)	return true;
	else	return false;
}

bool isOk(int len)
{
	if (len >= 2)
	{
		if (result[len - 1] < result[len - 2])	return false;
	}

	return true;
}

void f(int len)
{
	if (!isOk(len))	return;
	if (len == L)
	{
		if (!isPossible(result))	return;

		cout << result << "\n";
		return;
	}
	else
	{
		for (int i = 0; i < C; i++)
		{
			if (!check[i])
			{
				check[i] = true;
				result[len] = alpha[i];
				f(len + 1);
				check[i] = false;
				result[len] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char a;
	char tt[4] = { 't','c','w','s' };
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> a;
		alpha[i] = a;
	}

	sort(alpha, alpha + C);

	f(0);
	
	return 0;
}