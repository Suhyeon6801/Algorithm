#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 1000000000;
vector<long long>num;
vector<string>v;
stack<long long> st;

int NUM(long long X)
{
	st.push(X);
	return 0;
}

int POP()
{
	if (st.empty())	return 1;

	st.pop();
	return 0;
}

int INV()
{
	if (st.empty())	return 1;

	long long a = -(st.top());
	st.pop();
	st.push(a);
	return 0;
}

int DUP()
{
	if (st.empty())	return 1;

	long long a = st.top();
	st.push(a);
	return 0;
}

int SWP()
{
	if (st.empty())	return 1;

	long long fir = st.top();
	st.pop();

	if (st.empty())	return 1;

	long long sec = st.top();
	st.pop();

	st.push(fir);
	st.push(sec);

	return 0;
}

int ADD()
{
	if (st.empty())	return 1;

	long long fir = st.top();
	st.pop();

	if (st.empty())	return 1;

	long long sec = st.top();
	st.pop();

	st.push(fir + sec);
	return 0;
}

int SUB()
{
	if (st.empty())	return 1;

	long long fir = st.top();
	st.pop();

	if (st.empty())	return 1;

	long long sec = st.top();
	st.pop();

	st.push(sec - fir);
	return 0;
}

int MUL()
{
	if (st.empty())	return 1;

	long long fir = st.top();
	st.pop();

	if (st.empty())	return 1;

	long long sec = st.top();
	st.pop();

	st.push(fir*sec);
	return 0;
}

int DIV()
{
	int minus = 0;
	if (st.empty())	return 1;

	long long fir = st.top();
	st.pop();

	if (fir < 0)	minus++;

	if (st.empty())	return 1;

	long long sec = st.top();
	st.pop();

	if (sec < 0)	minus++;

	if (fir == 0)	return 1;

	fir = sec / fir;
	if (minus == 1)	fir = -(abs(fir));
	else
		fir = abs(fir);

	st.push(fir);
	return 0;
}

int MOD()
{
	int minus = 0;
	if (st.empty())	return 1;

	long long fir = st.top();
	st.pop();

	//if (fir < 0)	minus++; -> MOD는 sec가 음수인지 아닌지!

	if (st.empty())	return 1;

	long long sec = st.top();
	st.pop();

	if (sec < 0)	minus++;

	if (fir == 0)	return 1;

	fir = sec % fir;

	if (minus == 1)	fir = -(abs(fir));
	else
		fir = abs(fir);

	st.push(fir);
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	long long X;
	string cmd;

	while (1)
	{
		int check = 0;
		while (1)
		{
			cin >> cmd;

			if (cmd == "QUIT")	return 0;

			if (cmd == "NUM")
			{
				cin >> X;
				num.push_back(X);
			}

			if (cmd == "END")	break;

			v.push_back(cmd);
		}

		cin >> N;
		while(N--)
		{
			int idx = 0;
			cin >> M;
			st.push(M);

			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] == "NUM")
				{
					check = NUM(num[idx]);
					idx++;
				}
				else if (v[i] == "POP")	check = POP();
				else if (v[i] == "INV")	check = INV();
				else if (v[i] == "DUP")	check = DUP();
				else if (v[i] == "SWP")	check = SWP();
				else if (v[i] == "ADD")	check = ADD();
				else if (v[i] == "SUB")	check = SUB();
				else if (v[i] == "MUL")	check = MUL();
				else if (v[i] == "DIV")	check = DIV();
				else if (v[i] == "MOD")	check = MOD();

				if (!st.empty() && (st.top() > MAX || st.top() < -MAX))
					check = 1;

				if (check==1)	break;
			}

			if (check==1 || st.size() != 1)
				cout << "ERROR\n";
			else
				cout << st.top() << "\n";

			while (!st.empty())
			{
				st.pop();
			}
		}

		v.clear();
		num.clear();
		cout << "\n";
	}

	return 0;
}