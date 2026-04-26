from collections import deque


def is_switch(origin, target):
    diff_count = 0

    for a, b in zip(origin, target):
        if a != b:
            diff_count += 1

        if diff_count > 1:
            return False

    return diff_count == 1


def solution(begin, target, words):
    answer = 0

    if not target in words:
        return answer

    checked = [False] * len(words)
    queue = deque()
    queue.append((begin, 0))

    while queue:
        curr_word, count = queue.popleft()

        if curr_word == target:
            return count

        for i in range(len(words)):
            if not checked[i] and is_switch(curr_word, words[i]):
                checked[i] = True
                queue.append((words[i], count + 1))

    return answer


if __name__ == '__main__':
    solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"])
