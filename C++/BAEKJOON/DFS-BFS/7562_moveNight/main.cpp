
//////////////////////////////////////////////////
// BAEKJOON_7562번: 나이트의 이동
//////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct coordinate {
	int x;
	int y;
};

int chessMap[300][300];
bool visitedChessMap[300][300];
int TC, chessMapSize, ans_minMove;
int nightx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int nighty[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
coordinate startC;
coordinate endC;
void moveNightBFS() {
	queue<coordinate> q;
	q.push(startC);
	visitedChessMap[startC.x][startC.y] = true;

	while (!q.empty()) {
		int xx = q.front().x;
		int yy = q.front().y;

		q.pop();
		if (xx == endC.x && yy == endC.y) {
			ans_minMove = chessMap[xx][yy];
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nx = xx + nightx[i];
			int ny = yy + nighty[i];

			if (nx >= 0 && ny >= 0 && nx < chessMapSize && ny < chessMapSize && visitedChessMap[nx][ny] == false) {
				q.push({ nx,ny });
				visitedChessMap[nx][ny] = true;
				chessMap[nx][ny] = chessMap[xx][yy] + 1;
			}
		}
		ans_minMove++;
	}
}

void moveNight() {
	cin >> TC;
	queue<int> result;
	for (int i = 0; i < TC; i++) {
		memset(chessMap, 0, sizeof(chessMap));
		memset(visitedChessMap, false, sizeof(visitedChessMap));
		cin >> chessMapSize;

		cin >> startC.x >> startC.y;
		cin >> endC.x >> endC.y;
		ans_minMove = 0;

		moveNightBFS();
		
		result.push(ans_minMove);
	}
	
	for (int i = 0; i < TC; i++) {
		cout << result.front() << "\n";
		result.pop();
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	moveNight();
	
	return 0;
}