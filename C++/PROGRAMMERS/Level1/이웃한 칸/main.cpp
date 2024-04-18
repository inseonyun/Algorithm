#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, 1, -1};
bool checked[8][8] = { false, };

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int board_size = board.size();
    string color = board[h][w];
    checked[h][w] = true;
        
    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + h;
        int ny = dy[i] + w;

        if (nx >= 0 && ny >= 0 && nx < board_size && ny < board_size) {
            string nc = board[nx][ny];
            if (checked[nx][ny] == false && color == nc) {
                answer++;
            }
        }
    }
    
    return answer;
}
