
//////////////////////////////////////////////////
// BAEKJOON_11723번 : 집합
//////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int arr[21] = { 0, };

void adding(int number) {
	arr[number] = number;
}

void removing(int number) {
	arr[number] = 0;
}

void toggleNumber(int number) {
	if (arr[number] == 0) {
		arr[number] = number;
	}
	else
		arr[number] = 0;
}

void allNumber() {
	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}
}

void emptyNumber() {
	for (int i = 1; i <= 20; i++) {
		arr[i] = 0;
	}
}

int checking(int number) {
	int result = 0;

	if (arr[number] != 0)
		result = 1;

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string str;
		int n;
		cin >> str;
			
		if (str.compare("all") == 0) {
			allNumber();
			continue;
		}
		else if (str.compare("empty") == 0) {
			emptyNumber();
			continue;
		}
		cin >> n;

		if (str.compare("add") == 0) {
			adding(n);
		}
		else if (str.compare("remove") == 0) {
			removing(n);
		}
		else if (str.compare("toggle") == 0) {
			toggleNumber(n);
		}
		else {
			cout << checking(n) << "\n";
		}
	}

	return 0;
}