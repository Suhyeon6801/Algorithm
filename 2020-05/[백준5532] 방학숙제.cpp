#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L, A, B, C, D;
	int result;
	cin >> L >> A >> B >> C >> D;

	int korean = A / C;
	int math = B / D;

	if (A%C != 0)
		korean++;

	if (B%D != 0)
		math++;

	if (korean > math)
		result = L - korean;
	else
		result = L - math;

	cout << result << "\n";
	
	return 0;
}