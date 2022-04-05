
//////////////////////////////////////////////////
// BAEKJOON_2667번 : 단지번호붙이기
//////////////////////////////////////////////////

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[] = { 1, 0 , -1, 0};
int dy[] = { 0, 1, 0, -1 };
int map_size;
int complexMap[25][25];
vector <int> cnt;
int now_count;
void complexNumberBFS(int startX, int startY) {
	queue<pair<int, int>> q;

	q.push(make_pair(startX, startY));

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();
		if (complexMap[xx][yy] > 0) {
			now_count++;
			complexMap[xx][yy] = 0;

			for (int i = 0; i < 4; i++) {
				int nx = xx + dx[i];
				int ny = yy + dy[i];

				if (nx >= 0 && ny >= 0 && nx < map_size && ny < map_size) {
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void complexNumberDFS(int startX, int startY) {
	if (complexMap[startX][startY] > 0) {
		now_count++;
		complexMap[startX][startY] = 0;

		for (int i = 0; i < 4; i++) {
			int nx = startX + dx[i];
			int ny = startY + dy[i];

			if (nx >= 0 && ny >= 0 && nx < map_size && ny < map_size) {
				complexNumberDFS(nx, ny);
			}
		}
	}
}

void attachComplexNumber() {
	cin >> map_size;

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			scanf("%1d", &complexMap[i][j]);
		}
	}

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			if (complexMap[i][j] > 0) {
				now_count = 0;
				complexNumberBFS(i, j);
				cnt.push_back(now_count);
			}
		}
	}

	sort(cnt.begin(), cnt.end());
	cout << cnt.size() << "\n";

	for (int i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << "\n";
	}

}

int main() {
	attachComplexNumber();

	return 0;
}