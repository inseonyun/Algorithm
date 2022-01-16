#include <iostream>
#include <algorithm>

using namespace std;

int view_count;
int tc = 1;

void process(int a[], int b);
void printResult(int a);

void inputData() {
	int T = 10, test_case;
	
	for (test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;

		int* Apart = new int[N];

		for (int i = 0; i < N; i++) {
			cin >> Apart[i];
		}
		view_count = 0;
		process(Apart, N);

		printResult(view_count);
	}
}

void process(int Apart[], int N) {
	for (int i = 2; i < N - 2; i++) {
		int left, left2, right, right2;
		left = Apart[i] - Apart[i - 1];
		left2 = Apart[i] - Apart[i - 2];
		right = Apart[i] - Apart[i + 1];
		right2 = Apart[i] - Apart[i + 2];
		int value = 0;
		int tmp = 0;
		if (((left >= 1 && right >= 1) || (left >= 2 && right >= 2)) && left2 >= 1 && right2 >= 1) {
			tmp = min(left, right);
			value = min(left2, right2);
			value = min(value, tmp);
			view_count = view_count + value;
		}/*
		else if (left >= 2 && right >= 2 && left2 >= 2 && right2 >= 2) {
			tmp = min(left, right);
			value = min(left2, right2);
			value = min(value, tmp);
			view_count = view_count + 2;
		}*/
	}
}

void printResult(int view_count) {
	cout << "#" << tc << " " << view_count << "\n";
	tc++;
}

int main() {
	inputData();

	return 0;
}