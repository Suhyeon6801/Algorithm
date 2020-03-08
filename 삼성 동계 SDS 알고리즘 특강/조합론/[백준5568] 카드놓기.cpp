#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int arr[10];
int result[5];
bool visited[10];
int n, k;
set<int> numbers;

void f(int x) {
	if (x == k) 
	{
		int temp = 0;
		for (int i = 0; i < k; i++)
		{
			if (result[i] < 10)
				temp = temp*10 + result[i];
			else if (result[i] >= 10)
				temp = temp*100 + result[i];
			//temp = temp * (result[i] < 10 ? 10 : 100) + result[i];
		}
		numbers.insert(temp);
		return;
	}
	else 
    {
		for (int i = 0; i < n; i++)
        {
			if (!visited[i]) 
            {
				visited[i] = true;
				result[x] = arr[i];
				f(x + 1);
				visited[i] = false;
				result[x] = 0;
			}
        }
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	f(0);
	cout << numbers.size() << "\n";

	/*for (auto it = numbers.begin(); it != numbers.end(); it++)
		cout << *it << "\n";*/
	return 0;
}