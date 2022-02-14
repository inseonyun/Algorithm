
//////////////////////////////////////////////////
// BAEKJOON_2606번: 바이러스
//////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

vector<int> v[101];
queue<int> q;
bool check[101];
int virus_cnt = 0;

void DFS(int x) {
	check[x] = true;

	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (!check[y]) {
			virus_cnt++;
			DFS(y);
		}
	}
}

void BFS() {
	check[1] = true;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();

		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!check[y]) {
				check[y] = true;
				virus_cnt++;
				q.push(y);
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	memset(check, false, sizeof(check));

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	DFS(1);
	//BFS();

	cout << virus_cnt << "\n";

	return 0;
}