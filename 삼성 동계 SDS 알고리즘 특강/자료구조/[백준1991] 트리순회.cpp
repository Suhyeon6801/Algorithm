#include <iostream>

using namespace std;

struct Tree
{
	char root;
	char left;
	char right;
};

Tree tree[30];

void preorder(char c)
{
	if (tree[c].left == '.'&&tree[c].right == '.')
	{
		cout << c;
	}
	else
	{
		cout << c;
		
		if (tree[c].left != '.')
			preorder(tree[c].left);

		if (tree[c].right != '.')
			preorder(tree[c].right);
	}
}

void inorder(char c)
{
	if (tree[c].left == '.'&&tree[c].right == '.')
	{
		cout << c;
	}
	else
	{
		if (tree[c].left != '.')
			inorder(tree[c].left);

		cout << c;

		if (tree[c].right != '.')
			inorder(tree[c].right);
	}
}

void postorder(char c)
{
	if (tree[c].left == '.'&&tree[c].right == '.')
	{
		cout << c;
	}
	else
	{
		if (tree[c].left != '.')
			postorder(tree[c].left);

		if (tree[c].right != '.')
			postorder(tree[c].right);

		cout << c;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	char root, left, right;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> root >> left >> right;

		tree[root].left = left;
		tree[root].right = right;
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');

	return 0;
}