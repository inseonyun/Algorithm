
//////////////////////////////////////////////////
// BAEKJOON_5014번: 스타트링크
//////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// F : 건물 전체 층수, S : 현재 위치, G : 목적지, U : 위로 가는 층수, D : 아래로 가는 층수 
long long F, S, G, U, D;
long long floorDP[1000001];
void startLinkBFS() {
	floorDP[S] = 1;

	queue<int> q;

	q.push(S);

	while (!q.empty()) {
		int now = q.front();

		q.pop();

		if (now == G) {
			return;
		}

		int nextUp = now + U;
		int nextDown = now - D;

		if (nextUp <= F && floorDP[nextUp] == 0) {
			floorDP[nextUp] = floorDP[now] + 1;
			q.push(nextUp);
		}
		if (nextDown >= 1 && floorDP[nextDown] == 0) {
			floorDP[nextDown] = floorDP[now] + 1;
			q.push(nextDown);
		}
	}
}

void startLink() {
	cin >> F >> S >> G >> U >> D;

	memset(floorDP, 0, sizeof(floorDP));

	startLinkBFS();

	if (floorDP[G])
		cout << floorDP[G]-1 << "\n";
	else
		cout << "use the stairs\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	startLink();

	return 0;
}