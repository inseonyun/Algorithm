from collections import deque

n, m = map(int, input().split())
graph = []
queue = deque()
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


def bfs():
    while queue:
        now_x, now_y = queue.popleft()

        for next_idx in range(4):
            next_x = now_x + dx[next_idx]
            next_y = now_y + dy[next_idx]

            if 0 <= next_x < m and 0 <= next_y < n:
                if graph[next_x][next_y] == 0:
                    graph[next_x][next_y] = graph[now_x][now_y] + 1
                    queue.append((next_x, next_y))


def solve():
    for i in range(m):
        inputs = list(map(int, input().split()))
        graph.append(inputs)

        for j, value in enumerate(inputs):
            if value == 1:
                queue.append((i, j))

    bfs()

    result = 0
    for i in range(m):
        for j in range(n):
            if graph[i][j] == 0:
                print(-1)
                return

            if result < graph[i][j]:
                result = graph[i][j]

    print(result - 1)


if __name__ == '__main__':
    solve()
