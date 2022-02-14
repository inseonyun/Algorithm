
//////////////////////////////////////////////////
// SWEA_1824. 혁진이의 프로그램 검증_D4
//////////////////////////////////////////////////

#include <iostream>

using namespace std;

class Programming {
	int row, col;
	char program[20][20];
	bool check[20][20][4][16];

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };

	bool result = false;
	bool possible = false;

public:
	Programming() {
		inputData();
	}

	void inputData() {
		cin >> row >> col;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> program[i][j];

				if (program[i][j] == '@') {
					possible = true;
				}
				for (int k = 0; k < 4; k++) {
					for (int m = 0; m < 16; m++)
						check[i][j][k][m] = false;
				}
			}
		}
	}

	bool isPossible() {
		return possible;
	}

	void solution(int y, int x, int dir, int memo) {
		if (result) return;
		if (check[y][x][dir][memo])
			return;
		check[y][x][dir][memo] = true;
		char ch = program[y][x];
		int nx, ny, nd = dir, nmem = memo;
		
		if (ch == '?') {
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];

				if (nx == col) {
					nx = 0;
				}
				else if(nx < 0) {
					nx = col - 1;
				}
				else if (ny == row) {
					ny = 0;
				}
				else if (ny < 0) {
					ny = row - 1;
				}
				solution(ny, nx, i, nmem);
			}
		}
		else {
			if (ch == '^') {
				nd = 0;
			}
			else if (ch == '>') {
				nd = 1;
			}
			else if (ch == 'v') {
				nd = 2;
			}
			else if (ch == '<') {
				nd = 3;
			}
			else if (ch == '_') {
				nd = (nmem == 0 ? 1 : 3);
			}
			else if (ch == '|') {
				nd = (nmem == 0 ? 2 : 0);
			}
			else if (ch == '.') {
			}
			else if (ch == '@') {
				result = true;
				return;
			}
			else if (ch - '0' >= 0 && ch - '0' <= 9) {
				nmem = ch - '0';
			}
			else if (ch == '+') {
				nmem = (nmem == 15 ? 0 : nmem + 1);
			} 
			else if (ch == '-') {
				nmem = (nmem == 0 ? 15 : nmem - 1);
			}
			nx = x + dx[nd];
			ny = y + dy[nd];

			if (nx == col) {
				nx = 0;
			}
			else if (nx < 0) {
				nx = col - 1;
			}
			else if (ny == row) {
				ny = 0;
			}
			else if (ny < 0) {
				ny = row - 1;
			}

			solution(ny, nx, nd, nmem);
		}
	}
	bool getResult() {
		return result;
	}
};

int main() {
	int TC, test_case;
	cin >> TC;

	for (test_case = 1; test_case <= TC; test_case++) {
		Programming p;
		if (p.isPossible()) {
			p.solution(0, 0, 1, 0);
			if (p.getResult()) {
				cout << "#" << test_case << " " << "YES\n";
			}
			else {
				cout << "#" << test_case << " " << "NO\n";
			}
		}
		else {
			cout << "#" << test_case << " " << "NO\n";
		}
		
	}

	return 0;
}