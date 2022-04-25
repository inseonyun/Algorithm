
//////////////////////////////////////////////////
// BAEKJOON_2468번: 안전 영역
//////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int dx[] = { 1, 0 , -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int safeZoneMap[100][100];
bool visitedZone[100][100];
int maxHeight = -1;
int result = -1;
int now_count = 0;
int area_count = 0;
void safeZoneBFS(int startX, int startY, int height) {
	queue<pair<int, int>> q;

	q.push( { startX, startY } );

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		if (safeZoneMap[xx][yy] > height && visitedZone[xx][yy] == false) {
			now_count++;
			
			visitedZone[xx][yy] = true;

			for (int i = 0; i < 4; i++) {
				int nx = xx + dx[i];
				int ny = yy + dy[i];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
					q.push({ nx,ny });
				}
			}
		}
	}
}

void safeZone() {
	cin >> N;
	result = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> safeZoneMap[i][j];

			if (maxHeight < safeZoneMap[i][j]) {
				maxHeight = safeZoneMap[i][j];
			}
		}
	}

	for (int h = 0; h < maxHeight; h++) {
		area_count = 0;
		memset(visitedZone, false, sizeof(visitedZone));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (safeZoneMap[i][j] > h) {
					now_count = 0;
					safeZoneBFS(i, j, h);

					if (now_count) {
						area_count++;
					}
				}
			}
		}
		if (area_count > result) {
			result = area_count;
		}
	}
	cout << result;
}

int main() {

	safeZone();

	return 0;
}