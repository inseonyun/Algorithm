def is_match(user_id, banned_id):
    return len(user_id) == len(banned_id) and all(
        u == b or b == '*'
        for u, b in zip(user_id, banned_id)
    )


def dfs(user_id, banned_id, depth, selected, res):
    # 종료 조건
    if depth == len(banned_id):
        res.add(frozenset(selected))
        return

    curr_banned_id = banned_id[depth]

    for u in user_id:
        if u in selected:
            continue

        if is_match(u, curr_banned_id):
            selected.add(u)
            dfs(user_id, banned_id, depth + 1, selected, res)
            selected.remove(u)


def solution(user_id, banned_id):
    answer = set()

    dfs(user_id, banned_id, 0, set(), answer)

    return len(answer)

if __name__ == '__main__':
    print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["*rodo", "*rodo", "******"]))
