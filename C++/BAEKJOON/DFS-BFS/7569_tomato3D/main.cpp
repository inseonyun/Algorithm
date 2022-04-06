
//////////////////////////////////////////////////
// BAEKJOON_7569번: 토마토 3D
//////////////////////////////////////////////////

#include <iostream>
#include <queue>

using namespace std;

struct dimension {
	int D;
	int R;
	int C;
};

queue<dimension> q3D;
int tomato3DMap[100][100][100];
// 동, 남, 서, 북, 위, 아래
int dx3D[] = { 1, 0, -1, 0, 0, 0 };
int dy3D[] = { 0, 1, 0, -1, 0, 0 };
int dh3D[] = { 0, 0, 0, 0, 1, -1 };
int result = 0;
int D, R, C;

void tomato3DBFS() {
	while (!q3D.empty()) {
		int xx = q3D.front().R;
		int yy = q3D.front().C;
		int hh = q3D.front().D;

		q3D.pop();

		for (int i = 0; i < 6; i++) {
			int nx = xx + dx3D[i];
			int ny = yy + dy3D[i];
			int nh = hh + dh3D[i];

			if (nx >= 0 && ny >= 0 && nh >= 0 && nx < R && ny < C && nh < D) {
				if (tomato3DMap[nh][nx][ny] == 0) {
					tomato3DMap[nh][nx][ny] = tomato3DMap[hh][xx][yy] + 1;
					q3D.push({ nh, nx, ny });
				}
			}
		}
	}
}

void tomato3D() {
	int flag = 1;
	cin >> C >> R >> D;

	for (int i = 0; i < D; i++) {
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				cin >> tomato3DMap[i][j][k];

				if (tomato3DMap[i][j][k] == 1) {
					q3D.push({ i, j, k });
				}
			}
		}
	}

	for (int i = 0; i < D; i++) {
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (tomato3DMap[i][j][k] == 0) {
					flag = 0;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (!flag)
			break;
	}

	if (flag) {
		cout << 0 << "\n";
	}
	else {
		tomato3DBFS();

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (tomato3DMap[i][j][k] == 0) {
						cout << -1 << "\n";
						return;
					}

					if (result < tomato3DMap[i][j][k]) {
						result = tomato3DMap[i][j][k];
					}
				}
			}
		}

		cout << result -1 << "\n";
	}
}

int main() {
	tomato3D();

	return 0;
}