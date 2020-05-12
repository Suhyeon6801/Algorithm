#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Grade {
	string name;
	int kor, math, eng;
};

Grade grade[100010];

bool comp(Grade g1, Grade g2)
{
	if (g1.kor > g2.kor)	return true;
	else if (g1.kor == g2.kor)
	{
		if (g1.eng < g2.eng)	return true;
		else if (g1.eng == g2.eng)
		{
			if (g1.math > g2.math)	return true;
			else if (g1.math == g2.math)
				return g1.name < g2.name;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string name;
	int kor, eng, math;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> name >> kor >> eng >> math;
		grade[i].name = name, grade[i].kor = kor, grade[i].eng = eng, grade[i].math = math;
	}

	sort(grade, grade + N, comp);

	for (int i = 0; i < N; i++)
		cout << grade[i].name << "\n";
	
	return 0;
}