
//////////////////////////////////////////////////
// SWEA_1249. [S/W 문제해결 응용] 4일차 - 보급로_D4
//////////////////////////////////////////////////

#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

class supplyRoad {
	int map_size;
	int map[100][100];
	int cost[100][100];
	bool chk[100][100];
	
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };

public:
	supplyRoad() {
		// 맵 생성
		createMap();
	}

	void createMap() {
		cin >> map_size;

		for (int i = 0; i < map_size; i++) {
			for (int j = 0; j < map_size; j++) {
				// 수가 연속해서 입력되기 때문에 scanf 사용
				scanf_s("%1d", &map[i][j]);

				//cost와 chk 초기화
				cost[i][j] = 0;
				chk[i][j] = false;
			}
		}
	}

	void BFS(int startX, int startY) {
		queue<pair<int, int>> q;
		chk[startX][startY] = true;

		q.push(make_pair(startX, startY));

		while (!q.empty()) {
			int xx = q.front().first;
			int yy = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = xx + dx[i];
				int ny = yy + dy[i];

				if (nx >= 0 && ny >= 0 && nx < map_size && ny < map_size) {
					// 현재 가려는 경로가 false 이거나
					// 가려고 하는 좌표의 총 비용이 현재 위치한 곳의 비용 + 그 칸의 비용보다 크면 해당 값으로 값을 갱신함
					if (chk[nx][ny] == false || cost[nx][ny] > cost[xx][yy] + map[nx][ny]) {
						chk[nx][ny] = true;
						cost[nx][ny] = cost[xx][yy] + map[nx][ny];
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}

	int getResult() {
		return cost[map_size - 1][map_size - 1];
	}
};

int main() {
	int TC, test_case;
	cin >> TC;

	for (test_case = 1; test_case <= TC; test_case++) {
		supplyRoad s;
		s.BFS(0, 0);
		cout << "#" << test_case << " " << s.getResult() << "\n";
	}
}