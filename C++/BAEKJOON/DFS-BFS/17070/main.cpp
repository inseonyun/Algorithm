#include <iostream>

using namespace std;

int N;
int map[17][17];
int dr[3] = { 0, 1, 1 };
int dc[3] = { 1, 1, 0 };
int res = 0;

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> map[i][j];
    }
  }
}

bool check(int r, int c) {
  return (r > 0 && r <= N && c > 0 && c <= N && map[r][c] == 0);
}

bool check_diagonal(int r, int c) {
  return (map[r + 1][c] == 0 && map[r][c + 1] == 0);
}

void dfs(int r, int c, int dir) {
  if (r == N && c == N) {
    res++;
    return;
  }

  for (int i = 0; i < 3; i++) {
    // 가로 일 때 세로로 이동 x
    // 세로 일 때 가로로 이동 x
    if ((dir == 0 && i == 2) || (dir == 2 && i == 0)) {
      continue;
    }

    int nr = r + dr[i];
    int nc = c + dc[i];
    if (check(nr, nc) == false || i == 1 && !check_diagonal(r, c))
    {
      continue;
    }
    dfs(nr, nc, i);
  }
}

void output() {
  cout << res << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	input();
	dfs(1, 2, 0);
	output();

  return 0;
}
