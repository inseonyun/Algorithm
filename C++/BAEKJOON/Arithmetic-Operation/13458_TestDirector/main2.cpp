#include <iostream>
#include <vector>

using namespace std;

// N 시험장 수
// B 총 감독관의 감시 가능 인원
// C 부 감독관의 감시 가능 인원
int N, B, C;
long long res = 0;
vector<int> A;

void input() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;

    A.push_back(a);
  }
  
  cin >> B >> C;
}

void solution() {
  for (int i = 0; i < N; i++) {
    int div = A[i] - B;

    res++;

    if (div > 0) {
      int sub = div / C + ((div % C > 0) ? 1 : 0);

      res += sub;
    }
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
	solution();
	output();
}
