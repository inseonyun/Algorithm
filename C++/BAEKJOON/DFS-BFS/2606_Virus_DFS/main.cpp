
//////////////////////////////////////////////////
// BAEKJOON_2606번: 바이러스
//////////////////////////////////////////////////

#include <iostream>
#include <queue>

using namespace std;

vector <int> v[101];
bool check[101];
int computerN, edgeN, total = 0;

using namespace std;

void DFS(int x) {
	check[x] = true;

	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (!check[y]) {
			total++;
			DFS(y);
		}
	}
}

int main() {
	cin >> computerN >> edgeN;

	for (int i = 0; i < edgeN; i++) {
		int a, b;

		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	DFS(1);

	cout << total;

	return 0;
}