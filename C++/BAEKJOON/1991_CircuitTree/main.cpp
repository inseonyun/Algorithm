
//////////////////////////////////////////////////
// BAEKJOON_1991번: 트리 순회
//////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

struct node {
	char left;
	char right;
};

vector <node> v(26);

void preOrder(char root) {
	if (root == '.')
		return;

	cout << root;
	preOrder(v[root - 'A'].left);
	preOrder(v[root - 'A'].right);
}

void inOrder(char root) {
	if (root == '.')
		return;

	inOrder(v[root - 'A'].left);
	cout << root;
	inOrder(v[root - 'A'].right);
}

void postOrder(char root) {
	if (root == '.')
		return;
	postOrder(v[root - 'A'].left);
	postOrder(v[root - 'A'].right);
	cout << root;
}

int main() {
	int n;
	cin >> n;

	char root, left, right;

	for (int i = 0; i < n; i++) {
		cin >> root >> left >> right;
		v[root - 'A'].left = left;
		v[root - 'A'].right = right;
	}

	preOrder('A');
	cout << endl;

	inOrder('A');
	cout << endl;

	postOrder('A');

	return 0;
}