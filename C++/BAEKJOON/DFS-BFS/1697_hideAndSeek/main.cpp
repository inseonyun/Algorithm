
//////////////////////////////////////////////////
// BAEKJOON_1697번: 숨바꼭질
//////////////////////////////////////////////////

#include    <iostream>
#include    <cstring>
#include    <queue>

using namespace std;

int hasMap[100001];
bool checkHasMap[100001];
int N, K;
int hideAndSeekBFS(int startX) {
	checkHasMap[startX] = true;

	queue<int> q;
	q.push(startX);
	int count = 0;
	while (true) {
		int size = q.size();

		for (int i = 0; i < size; i++) {

			int xx = q.front();

			q.pop();

			if (xx == K)
				return count;

			if (xx > 0 && checkHasMap[xx - 1] == false) {
				q.push(xx - 1);
				checkHasMap[xx - 1] = true;
			}
			if (xx < 100001 && checkHasMap[xx + 1] == false) {
				q.push(xx + 1);
				checkHasMap[xx + 1] = true;
			}
			if (xx * 2 < 100001 && checkHasMap[xx * 2] == false) {
				q.push(xx * 2);
				checkHasMap[xx * 2] = true;
			}
		}
		count++;
	}
}

void hideAndSeek() {
	cin >> N >> K;

	memset(hasMap, 0, sizeof(hasMap));
	memset(checkHasMap, false, sizeof(checkHasMap));

	hasMap[K] = 1;

	cout << hideAndSeekBFS(N);
	
}

int main() {
	hideAndSeek();

	return 0;
}