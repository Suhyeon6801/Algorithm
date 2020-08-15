#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long double getArea(double a, double b, double c)//by 헤론의 공식
{
	long double s = (a + b + c) / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}

long double getSum(double a, double b, double c, double R)
{
	long double temp1 = sqrt(R*R - a * a);
	long double temp2 = sqrt(R*R - b * b);
	long double temp3 = sqrt(R*R - c * c);
	//sum += sqrt(R*R - a * a) + sqrt(R*R - b * b) + sqrt(R*R*-c * c);
	return temp1 + temp2 + temp3;
}

int main()
{
	double x, y, z;
	long double area, Rad, r, d, k;
	scanf("%lf %lf %lf", &x, &y, &z);

	area = getArea(x, y, z);
	Rad = (x*y*z) / (4 * area);
	r = (2 * area) / (x + y + z);
	d = max((long double)0,sqrt(Rad*Rad - 2 * r*Rad));
	k = getSum(x/2, y/2, z/2, Rad);

	printf("%0.10f\n", area);
	printf("%0.10f\n%", Rad);
	printf("%0.10f\n", r);
	if (x == y && y == z)	d = 0;
	printf("%0.10f\n", d);
	printf("%0.10f\n",k);

	return 0;
}