#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string channel;
	cin >> N;

	int idx1 = -1, idx2 = -1;

	for (int i = 0; i < N; i++)
	{
		cin >> channel;

		if (channel == "KBS1")
			idx1 = i;
		else if (channel == "KBS2")
			idx2 = i;
	}

	int check;//KBS1이랑 2가 정렬되어 있는지 확인.
	if (idx1 > idx2)
		check = 1;
	else
		check = 0;

	//KBS1을 찾을 때 까지 1번으로 화살표 내리기
	for (int i = 0; i < idx1; i++)
		cout << "1";
	
	//KBS1을 제일 위까지 4번으로 올린다.
	for (int i = 0; i < idx1; i++)
		cout << "4";

	//KBS2를 찾을 때까지 1번으로 화살표 내리기
	for (int i = 0; i < idx2 + check; i++)
		cout << "1";

	//KBS2를 1번 바로 위까지 올리기
	for (int i = 0; i < idx2 + check - 1; i++)
		cout << "4";
	cout << "\n";

	return 0;
}