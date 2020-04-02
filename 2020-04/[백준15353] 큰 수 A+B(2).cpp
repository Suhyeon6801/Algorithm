#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A, B;

void getSum()
{
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int sum = 0, carry = 0;
	string temp = "";
	for (int i = 0; i < A.length(); i++)
	{
		if (i < B.length())
		{
			sum = (A[i] - '0' + B[i] - '0' + carry) % 10;
			temp += sum + '0';
			carry = (A[i] - '0' + B[i] - '0' + carry) / 10;
		}
		else
		{
			sum = (A[i] - '0' + carry) % 10;
			temp += sum + '0';
			carry= (A[i] - '0' + carry) / 10;
		}
	}
	temp += carry + '0';

	reverse(temp.begin(), temp.end());
	int idx = 0;
	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] != '0')
		{
			idx = i;
			break;
		}
	}
	
	cout << temp.substr(idx, temp.size());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;

	if (A.length() < B.length())
	{
		swap(A, B);
		getSum();
	}
	else
		getSum();

	return 0;
}