
//////////////////////////////////////////////////
// SWEA_1227. [S/W 문제해결 기본] 7일차 - 미로2_D4
//////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <cstring>
#include <stdio.h>

using namespace std;

class Maze {
	int map[100][100];
	bool visited[100][100];
	int x, y;
	int result;
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };

public:
	Maze() {
		result = 0;
		createMap();
	}

	void createMap() {
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
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
		queue <pair <int, int>> q;
		visited[x][y] = true;
		q.push(make_pair(x, y));

		while (!q.empty()) {
			int xx = q.front().first;
			int yy = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = xx + dx[i];
				int ny = yy + dy[i];

				if (nx >= 0 && dy >= 0 && nx < 100 && ny < 100) {
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
