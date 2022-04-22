
//////////////////////////////////////////////////
// BAEKJOON_2644번: 촌수계산
//////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m, a, b; // n = 사람 수, m = 부모 자식 간의 관계 수, a와 b의 촌수 계산
int family[101][101];
int dp[101];
void calcDegreeOfKinshipBFS(int start) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();

		q.pop();

		for (int i = 1; i <= n; i++) {
			if (family[now][i] == 1 && dp[i] == 0) {
				dp[i] = dp[now] + 1;
				q.push(i);
			}
		}
	}
}

void calcDegreeOfKinship() {
	cin >> n;
	cin >> a >> b;
	cin >> m;

	memset(family, 0, sizeof(family));
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < m; i++) {
		int parent, child;
		cin >> parent >> child;

		family[parent][child] = 1;
		family[child][parent] = 1;
	}

	calcDegreeOfKinshipBFS(a);

	if (dp[b] == 0)
		cout << "-1\n";
	else
		cout << dp[b] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	calcDegreeOfKinship();

	return 0;
}