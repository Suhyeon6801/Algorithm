/*'기하 알고리즘'의 필수적인 알고리즘
CCW = Counter Clockwise, 평면 위에 놓여진 세 점의 방향 관계를 구할 수 있는 알고리즘
점 A,B,C를 순서대로 봤을 때 반시계 방향으로 놓여 있으면 양수, 시계방향이면 음수, 평헹하면 0
벡터로 놓았을 때, 외적으로 방향을 판단 할 수 있음
*/

#include <iostream>
using namespace std;

int ccw(int a1, int b1, int a2, int b2, int a3, int b3)
{
	return (a1*b2 + a2 * b3 + a3 * b1) - (a2*b1 + a3 * b2 + a1 * b3); 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x1, y1, x2, y2, x3, y3;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int res=ccw(x1, y1, x2, y2, x3, y3);

	if (res == 0)	cout << "0\n";
	else if (res < 0)	cout << "-1\n";
	else if (res > 0)	cout << "1\n";

	return 0;

}