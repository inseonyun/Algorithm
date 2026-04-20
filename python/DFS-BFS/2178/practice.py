import sys
from collections import deque


def bfs(dp, board, N, M):
    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]

    queue = deque([(0, 0)])
    dp[0][0] = 1
    while queue:
        x, y = queue.popleft()
        cost = dp[x][y]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < M:
                if board[nx][ny] == 1:
                    if cost + 1 < dp[nx][ny]:
                        dp[nx][ny] = cost + 1
                        queue.append((nx, ny))


def solve():
    N, M = map(int, input().split())
    dp = [[sys.maxsize] * M for _ in range(N)]

    # 구분이 없는 연속된 수 입력
    board = [list(map(int, input())) for _ in range(N)]

    bfs(dp, board, N, M)

    print(dp[N-1][M-1])


if __name__ == '__main__':
    solve()