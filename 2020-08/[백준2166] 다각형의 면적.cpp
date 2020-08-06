#include <cstdio>
#include <cmath>
using namespace std;

struct Point {
	double x, y;
};

Point p[10010];
long double sum;

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%lf %lf", &p[i].x, &p[i].y);

	p[N].x = p[0].x, p[N].y = p[0].y;

	for (int i = 0; i < N; i++)
		sum += ((p[i].x*p[i + 1].y) / 2 - (p[i + 1].x*p[i].y) / 2);

	printf("%.1Lf", fabs(sum));//double은 %lf, long double은 %Lf

	return 0;
}