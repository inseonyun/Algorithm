from collections import deque

computer_cnt = int(input().strip())
graph = [[] for _ in range(computer_cnt + 1)]
visited = [False for _ in range(computer_cnt + 1)]

def bfs(start) -> int:
    queue = deque([start])
    visited[start] = True
    # 1번 시작 노드의 감염은 제외함
    res = -1

    while queue:
        node = queue.popleft()
        res += 1

        for next_node in graph[node]:
            if not visited[next_node]:
                visited[next_node] = True
                queue.append(next_node)

    return res

def solve():
    connected_cnt = int(input().strip())

    for _ in range(connected_cnt):
        a, b = map(int, input().strip().split(' '))
        graph[a].append(b)
        graph[b].append(a)

    print(bfs(1))

if __name__ == '__main__':
    solve()