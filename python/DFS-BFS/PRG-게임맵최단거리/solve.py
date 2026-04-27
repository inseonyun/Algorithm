import sys
from collections import deque


def solution(maps):
    n = len(maps)
    m = len(maps[0])
    dp = [[sys.maxsize] * m for _ in range(n)]

    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]

    def bfs():
        queue = deque()
        dp[0][0] = 1
        queue.append((0, 0))

        while queue:
            x, y = queue.popleft()
            cost = dp[x][y]

            for idx in range(4):
                nx, ny = x + dx[idx], y + dy[idx]

                if 0 <= nx < n and 0 <= ny < m:
                    if maps[nx][ny] == 1:
                        if dp[nx][ny] > cost + 1:
                            dp[nx][ny] = cost + 1
                            queue.append((nx, ny))

    bfs()

    if dp[n - 1][m - 1] == sys.maxsize:
        return -1

    return dp[n - 1][m - 1]


if __name__ == '__main__':
    print(solution([[1, 0, 1, 1, 1], [1, 0, 1, 0, 1], [1, 0, 1, 1, 1], [1, 1, 1, 0, 1], [0, 0, 0, 0, 1]]))
