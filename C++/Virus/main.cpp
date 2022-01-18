
//////////////////////////////////////////////////
// BAEKJOON_2606번: 바이러스
//////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector <int> v[101];
queue <int> q;
bool visited[101];
int N, M;
int virusN = 0;

void DFS(int x) {
	visited[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (!visited[y]) {
			virusN++;
			DFS(y);
		}
	}
}

void BFS() {
	visited[1] = true;

	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (visited[y] == false) {
				visited[y] = true;
				virusN++;
				q.push(y);
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);

	}
	//memset(visited, false, sizeof(visited));
	//DFS(1);

	//virusN = 0;
	memset(visited, false, sizeof(visited));
	BFS();

	cout << virusN << "\n";

	return 0;
}