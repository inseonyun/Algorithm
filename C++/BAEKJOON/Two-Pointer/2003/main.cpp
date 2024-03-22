#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int N, M;
  cin >> N >> M;
  
  int arr[10000];
  for (int i = 0; i < N; i++) {
      cin >> arr[i];
  }
  
  int start_index = 0;
  int end_index = 0;
  long long sum = arr[0];
  long long count = 0;
  
  while (start_index < N && end_index < N) {
      if (sum == M) {
          count++;
          sum += arr[++end_index];
      }
      else if (sum > M) {
          sum -= arr[start_index++];
      }
  
      else {
          sum += arr[++end_index];
      }
  }
  
  cout << count << "\n";
  return 0;
}
