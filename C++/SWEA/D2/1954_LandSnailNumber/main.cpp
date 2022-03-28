
//////////////////////////////////////////////////
// SWEA_1954. 달팽이 숫자 D2
//////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[10][10];
bool check[10][10];
int T, test_case, numSize, k;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void DFS(int x, int y, int r) {
	check[x][y] = true;
	arr[x][y] = k++;

	for (int i = r; i < r + 4; i++) {
		int nx = x + dx[i % 4];
		int ny = y + dy[i % 4];

		if (nx >= 0 && ny >= 0 && nx < numSize && ny < numSize) {
			if (check[nx][ny] == false) {
				DFS(nx, ny, i);
			}
		}
	}
}

int main() {
	cin >> T;

	for (test_case = 1; test_case <= T; test_case++) {
		cin >> numSize;

		memset(check, false, sizeof(check));

		k = 1;
		DFS(0, 0, 0);

		cout << "#" << test_case << "\n";
		for (int i = 0; i < numSize; i++) {
			for (int j = 0; j < numSize; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}