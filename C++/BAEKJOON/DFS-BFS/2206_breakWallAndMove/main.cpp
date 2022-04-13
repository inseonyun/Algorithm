
//////////////////////////////////////////////////
// BAEKJOON_2206번: 벽 부수고 이동
//////////////////////////////////////////////////

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;

int bwmMap[1000][1000];
int checkbwmMap[1000][1000][2];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int M, N;
int ans_move = 0;
void breakWallAndMoveBFS(int startX, int startY) {
	checkbwmMap[startX][startY][0] = 1;
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(startX, startY), 0));

	while (!q.empty()) {
		int xx = q.front().first.first;
		int yy = q.front().first.second;
		int bb = q.front().second;

		q.pop();

		if (xx == N - 1 && yy == M - 1) {
			ans_move = checkbwmMap[xx][yy][bb];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (bwmMap[nx][ny] == 1 && bb == 0) {
					checkbwmMap[nx][ny][bb + 1] = checkbwmMap[xx][yy][bb] + 1;
					q.push({ {nx, ny}, bb + 1});
				}
				if (bwmMap[nx][ny] == 0 && checkbwmMap[nx][ny][bb] == 0) {
					checkbwmMap[nx][ny][bb] = checkbwmMap[xx][yy][bb] + 1;
					q.push({ {nx,ny},bb });
				}
			}
		}
	}
}

void breakWallAndMove() {
	cin >> N >> M;

	memset(checkbwmMap, 0, sizeof(checkbwmMap));

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			scanf("%1d", &bwmMap[row][col]);
		}
	}
	
	breakWallAndMoveBFS(0, 0);

	if (ans_move == 0) {
		cout << -1;
	}
	else {
		cout << ans_move;
	}
}

int main() {
	breakWallAndMove();

	return 0;
}