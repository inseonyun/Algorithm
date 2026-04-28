def solution(numbers, target):
    def dfs(res, idx):
        if idx == len(numbers):
            return 1 if res == target else 0
        return dfs(res + numbers[idx], idx + 1) + dfs(res - numbers[idx], idx + 1)

    return dfs(0, 0)


if __name__ == '__main__':
    print(solution([1, 1, 1, 1, 1], 3))
