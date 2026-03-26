import sys
from collections import deque

n, m = map(int, input().strip().split())
board = [list(map(int, input())) for _ in range(n)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


# 시작 위치 (1, 1)
# 도착 위치 (n, m)
def solve():
    queue = deque()
    queue.append((0, 0))
    dp = [[sys.maxsize] * m for _ in range(n)]
    dp[0][0] = 1

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            next_x, next_y = x + dx[i], y + dy[i]
            if 0 <= next_x < n and 0 <= next_y < m:
                if board[next_x][next_y] == 1:
                    if dp[next_x][next_y] > dp[x][y] + 1:
                        dp[next_x][next_y] = dp[x][y] + 1
                        queue.append((next_x, next_y))

    print(dp[n - 1][m - 1])


if __name__ == "__main__":
    solve()
