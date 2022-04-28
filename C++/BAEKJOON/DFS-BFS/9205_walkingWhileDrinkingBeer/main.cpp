
//////////////////////////////////////////////////
// BAEKJOON_9205번: 맥주 마시면서 걸어가기
//////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coordinate {
	int x;
	int y;
};

int n;
vector<coordinate> cvStore;
vector <bool> visitedCVStore;
coordinate start;
coordinate festival;

void walkingWhileDrinkingBeerBFS() {
	queue <coordinate> q;

	q.push(start);

	while (!q.empty()) {
		int xx = q.front().x;
		int yy = q.front().y;

		q.pop();

		if (abs(xx - festival.x) + abs(yy - festival.y) <= 1000) {
			cout << "happy\n";
			return;
		}
		else {
			for (int i = 0; i < cvStore.size(); i++) {
				if (abs(xx - cvStore[i].x) + abs(yy - cvStore[i].y) <= 1000) {
					if (visitedCVStore[i] == false) {
						visitedCVStore[i] = true;

						q.push(coordinate{ cvStore[i].x, cvStore[i].y });
					}
				}
				
			}
		}
	}
	cout << "sad\n";
}

void walkingWhileDrinkingBeer() {
	int test_case;
	cin >> test_case;

	for (int TC = 0; TC < test_case; TC++) {
		cin >> n;
		cin >> start.x >> start.y;

		cvStore.clear();
		visitedCVStore = vector<bool>(n, false);

		for (int cv_count = 0; cv_count < n; cv_count++) {
			int tmpX, tmpY;
			cin >> tmpX >> tmpY;

			cvStore.push_back(coordinate{ tmpX, tmpY });
		}
		cin >> festival.x >> festival.y;

		walkingWhileDrinkingBeerBFS();
	}
}

int main() {

	walkingWhileDrinkingBeer();

	return 0;
}