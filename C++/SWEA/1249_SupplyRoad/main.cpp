
//////////////////////////////////////////////////
// SWEA_1249. [S/W �����ذ� ����] 4���� - ���޷�_D4
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
		// �� ����
		createMap();
	}

	void createMap() {
		cin >> map_size;

		for (int i = 0; i < map_size; i++) {
			for (int j = 0; j < map_size; j++) {
				// ���� �����ؼ� �ԷµǱ� ������ scanf ���
				scanf_s("%1d", &map[i][j]);

				//cost�� chk �ʱ�ȭ
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
					// ���� ������ ��ΰ� false �̰ų�
					// ������ �ϴ� ��ǥ�� �� ����� ���� ��ġ�� ���� ��� + �� ĭ�� ��뺸�� ũ�� �ش� ������ ���� ������
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