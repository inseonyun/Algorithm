
//////////////////////////////////////////////////
// BAEKJOON_1012번 : 유기농 배추
//////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int arr[50][50];
int dx[] = { 1, 0 , -1, 0};
int dy[] = { 0, 1, 0, -1 };
int M, N, K;
void organicCabbageDFS(int startX, int startY) {
	if (arr[startX][startY] == 1) {
		arr[startX][startY] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = startX + dx[i];
			int ny = startY + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				organicCabbageDFS(nx, ny);
			}
		}
	}

}
void organicCabbageBFS(int startX, int startY) {
	queue<pair<int, int>> q;

	q.push(make_pair(startX, startY));

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		if (arr[xx][yy] == 1) {
			arr[xx][yy] = 0;
			
			for (int i = 0; i < 4; i++) {
				int nx = xx + dx[i];
				int ny = yy + dy[i];

				if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void organicCabbage() {
	// M : 열 개수, N : 행 개수, K : 배추 개수
	int TC;
	cin >> TC;

	for (int test_case = 0; test_case < TC; test_case++) {
		cin >> M >> N >> K;

		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}

		int count = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) {
					organicCabbageBFS(i, j);
					++count;
				}
			}
		}

		cout << count << "\n";
	}
}

int main() {
	organicCabbage();

	return 0;
}