def dfs(curr, checked, computers):
    # 갱신
    checked[curr] = True

    # 탐색 조건
    for idx, isConnected in enumerate(computers[curr]):
        if isConnected == 0:
            continue
        elif idx == curr:
            continue

        if not checked[idx]:
            dfs(idx, checked, computers)


def solution(n, computers):
    answer = 0

    checked = [False for _ in range(n)]

    for i in range(n):
        if not checked[i]:
            dfs(i, checked, computers)
            answer += 1

    return answer
