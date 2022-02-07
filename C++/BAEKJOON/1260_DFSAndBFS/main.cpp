
//////////////////////////////////////////////////
// BAEKJOON_1260¹ø: DFS¿Í BFS
//////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> v[1001];
bool check[1001];
int n, m, startX;

void DFS(int x) {
	check[x] = true;
	cout << x << " ";

	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (!check[y]) {
			DFS(y);
		}
	}
}

void BFS(int x) {
	check[x] = true;

	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int xx = q.front();
		q.pop();

		cout << xx << " ";

		for (int i = 0; i < v[xx].size(); i++) {
			int y = v[xx][i];
			if (!check[y]) {
				check[y] = true;
				q.push(y);
			}
		}
	}
}

int main() {
	cin >> n >> m >> startX;

	memset(check, false, sizeof(check));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			sort(v[i].begin(), v[i].end());
		}
	}

	DFS(startX);
	cout << endl;

	memset(check, false, sizeof(check));

	BFS(startX);
	cout << endl;

	return 0;
}
