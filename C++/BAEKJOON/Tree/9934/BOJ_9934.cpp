
//////////////////////////////////////////////////
// BAEKJOON: 9934_완전 이진 트리
//////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int K, nodeCnt;
int tree[1025];
vector<int> answer[100];

void input() {
	cin >> K;

	nodeCnt = pow(2, K) - 1;
	for (int i = 0; i < nodeCnt; i++) {
		cin >> tree[i];
	}
}

void solution(int start, int end, int depth) {
	if (start == end) {
		answer[depth].push_back(tree[start]);
		
		return;
	}
	int idx_rootNode = (start + end) / 2;
	answer[depth].push_back(tree[idx_rootNode]);

	solution(start, idx_rootNode, depth + 1);
	solution(idx_rootNode + 1, end, depth + 1);
}

void output() {
	for (int i = 0; i < K; i++) {
		for (int j : answer[i]) {
			cout << j << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solution(0, nodeCnt -1, 0);
	output();

	return 0;
}