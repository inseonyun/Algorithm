
//////////////////////////////////////////////////
// SWEA_1226. [S/W 문제해결 기본] 7일차 - 미로1_D4
//////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>

using namespace std;

class DFS {
	int result = 0;
	int map[16][16];
	bool check[16][16];

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };

	int x, y;

public:
	DFS() {
		CreateMap();
	}

	void CreateMap() {
		memset(check, false, sizeof(check));

		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf_s("%1d", &map[i][j]);

				if (map[i][j] == 2) {
					x = i;
					y = j;
				}
			}
		}
		Search(x, y);
	}

	void Search(int x, int y) {
		check[x][y] = true;
		if (map[x][y] == 3) {
			result = 1;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < 16 && ny < 16) {
				if (check[nx][ny] == false && (map[nx][ny] == 0 || map[nx][ny] == 3))
					Search(nx, ny);
			}
		}
	}

	int GetResult() {
		return result;
	}
};

int main() {
	for (int test_case = 1; test_case <= 10; test_case++) {
		int T;
		cin >> T;

		DFS d;

		cout << "#" << test_case << " " << d.GetResult() << "\n";
	}

	return 0;
}