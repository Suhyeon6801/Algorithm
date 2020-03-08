#include <iostream>
using namespace std;

struct Tree {
	int left;
	int right;
};

Tree tree[1000010] = { 0, };

void postorder(int x)
{
	if (tree[x].left != 0)
		postorder(tree[x].left);

	if (tree[x].right != 0)
		postorder(tree[x].right);

	cout << x << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int node;
	int root;
	int leaf;
	cin >> root;
	while (cin >> leaf)
	{
		int node = root;
		while (1)
		{
			if (node < leaf)//오른쪽임 
			{
				if (tree[node].right != 0)//오른쪽에 자식이 있으면 오른쪽으로 진행, 얘가 부모가 됨.
				{
					node = tree[node].right;
				}
				else//자식이 없으면 넣어준다.
				{
					tree[node].right = leaf;
					break;
				}
			}
			else
			{
				if (tree[node].left != 0)
				{
					node = tree[node].left;
				}
				else
				{
					tree[node].left = leaf;
					break;
				}
			}
		}
	}
	postorder(root);
	return 0;
}