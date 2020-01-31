#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Person {
	int age;
	int order;
	string name;
};
Person p[100010];

bool comp(Person p1, Person p2)
{
	if (p1.age < p2.age)	return true;
	else if (p1.age == p2.age)
	{
		return p1.order < p2.order;
	}
	else
		return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].age >> p[i].name;
		p[i].order = i;
	}

	sort(p, p + n, comp);
	
	for (int i = 0; i < n; i++)
	{
		cout << p[i].age <<" "<< p[i].name << "\n";
	}
	return 0;
}