
//////////////////////////////////////////////////
// BAEKJOON_2178번: 미로 탐색
//////////////////////////////////////////////////

#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;

int row_size, col_size;
int mazeMap[100][100];
int leng[100][100];
bool checkMaze[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void searchMazeBFS(int startX, int startY) {
	checkMaze[startX][startY] = true;
	leng[startX][startY] = 1;

	queue <pair<int, int>> q;

	q.push(make_pair(startX, startY));

	while (!q.empty()) {
		int flag = 0;
		
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < row_size && ny < col_size) {
				if (checkMaze[nx][ny] == false && mazeMap[nx][ny] == 1) {
					leng[nx][ny] = leng[xx][yy] + 1;

					checkMaze[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void searchMaze() {
	// 출발점은 원점(0,0) 도착점은 (N-1, M-1)

	cin >> row_size >> col_size;

	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			scanf("%1d", &mazeMap[i][j]);
		}
	}
	memset(checkMaze, false, sizeof(checkMaze));
	searchMazeBFS(0, 0);

	cout << leng[row_size-1][col_size-1] << "\n";
}

int main() {
	searchMaze();

	return 0;
}