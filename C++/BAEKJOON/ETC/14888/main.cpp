#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int value_max = INT_MIN;
int value_min = INT_MAX;
int N;
vector<int> op(4, 0);
vector<int> v(11, 0);

void input() {
  cin >> N;
  
  for (int i = 0; i < N; i++) {
      cin >> v[i];
  }
  
  for (int i = 0; i < 4; i++) {
      cin >> op[i];
  }
}

void solution(int res, int idx) {
  if (idx == N) {
      value_max = max(value_max, res);
      value_min = min(value_min, res);
      return;
  }
  
  for (int i = 0; i < 4; i++) {
      if (op[i] <= 0) continue;
  
      op[i]--;
      switch(i) 
      {
          case 0:
              solution(res + v[idx], idx + 1);
              break;
          case 1:
              solution(res - v[idx], idx + 1);
              break;
          case 2:
              solution(res * v[idx], idx + 1);
              break;
          case 3:
              solution(res / v[idx], idx + 1);
              break;
      }
      op[i]++;
  }
}

void output() {
  cout << value_max << "\n" << value_min << "\n";  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  input();
  solution(v[0], 1);
  output();
  
  return 0;
}
