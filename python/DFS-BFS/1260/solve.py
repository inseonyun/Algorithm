from collections import deque

# N: 정점의 개수
# M: 간선의 개수
# V: 탐색 시작 정점 번호
n, m, v = map(int, input().strip().split())
graph = [[] for _ in range(n + 1)]


def dfs(start, visited, answers):
    visited[start] = True
    answers.append(start)
    for next in graph[start]:
        if not visited[next]:
            dfs(next, visited, answers)


def bfs(start):
    visited = [False] * (n + 1)
    visited[start] = True
    queue = deque([start])

    answers = []
    while queue:
        now = queue.popleft()
        answers.append(now)

        for next in graph[now]:
            if not visited[next]:
                visited[next] = True
                queue.append(next)

    return answers


def solve():
    for _ in range(m):
        a, b = map(int, input().strip().split())
        graph[a].append(b)
        graph[b].append(a)

    # 오름차순 정렬
    for i in range(1, n + 1):
        graph[i].sort()

    answers = []
    visited = [False] * (n + 1)
    dfs(v, visited, answers)

    for answer in answers:
        print(answer, end=" ")
    print()

    for answer in bfs(v):
        print(answer, end=" ")


if __name__ == "__main__":
    solve()
