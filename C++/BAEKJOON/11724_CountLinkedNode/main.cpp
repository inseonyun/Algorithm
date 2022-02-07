
//////////////////////////////////////////////////
// BAEKJOON_11724번: 연결 요소의 개수
//////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector <int> v[1001];
bool check[1001];

void DFS(int u) {
	check[u] = true;

	for (int i = 0; i < v[u].size(); i++) {
		int next = v[u][i];
		if (!check[next]) {
			DFS(next);
		}
	}
}

int main() {
	int n, m, cnt = 0;
	cin >> n >> m;

	memset(check, false, sizeof(check));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i < n; i++) {
		if (check[i])
			continue;
		DFS(i);
		cnt++;
	}
	cout << cnt;

	return 0;
}