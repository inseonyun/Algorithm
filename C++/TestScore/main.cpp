#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int count_case;
bool visited[10001];

void process(int socre[], int N);
void printResult();

void inputData() {
	int T, test_case;
	cin >> T;

	for (test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;

		int* score = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> score[i];
		}
		memset(visited, false, sizeof(visited));

		count_case = 0;
		process(score, N);
		printResult();
	}
}
void process(int score[], int N) {
	queue<int> q;
	for (int i = 0; i < N; i++) {
		q.push(score[i]);
	}
	
	
}

void printResult() {

}

int main() {
	inputData();

	return 0;
}