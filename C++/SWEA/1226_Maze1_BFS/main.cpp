
//////////////////////////////////////////////////
// SWEA_1226. [S/W 문제해결 기본] 7일차 - 미로1_D4
//////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

class Maze {
	int map[16][16];
	bool visited[16][16];
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };
	int x, y;
	int result = 0;

public :
	Maze() {
		createMap();
	}

	void createMap() {
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf_s("%1d", &map[i][j]);
				
				if (map[i][j] == 1) {
					visited[i][j] = true;
				}
				else if (map[i][j] == 2) {
					x = i;
					y = j;
				}
			}
		}
	}

	void BFS() {
		visited[x][y] = true;
		queue<pair<int, int>> q;
		q.push(make_pair(x, y));

		while (!q.empty()) {
			int xx = q.front().first;
			int yy = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = xx + dx[i];
				int ny = yy + dy[i];

				if (nx >= 0 && ny >= 0 && nx < 16 && ny < 16) {
					if (map[nx][ny] == 3) {
						result = 1;
					}
					else if (map[nx][ny] == 0 && visited[nx][ny] == false) {
						visited[nx][ny] = true;

						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}

	int getResult() {
		return result;
	}
};

int main() {
	int test_case;

	for (test_case = 1; test_case <= 10; test_case++) {
		int T;
		cin >> T;
		Maze m;

		m.BFS();
		int result = m.getResult();

		cout << "#" << test_case << " " << result << "\n";
	}

	return 0;
}