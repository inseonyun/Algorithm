def solution(triangle):
    depth = len(triangle)

    dp = [[0] * depth for _ in range(depth)]
    dp[0][0] = triangle[0][0]

    for i in range(1, len(triangle)):
        for j in range(len(triangle[i])):
            # 왼쪽 끝
            if j == 0:
                dp[i][j] = dp[i - 1][j] + triangle[i][j]

            # 오른쪽 끝
            elif j == len(triangle[i]) - 1:
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j]

            # 가운데
            else:
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]

    #     [0][0] = 7

    #     [1][0] = 10 (dp[0][0] + triangle[1][0])

    #     [2][0] = 18 (dp[1][0] + triangle[2][0])
    #     [2][1] = 11 (dp[1][0] + triangle[2][1])

    #     [1][1] = 15 (dp[0][0] + triangle[1][1])

    #     [2][1] = 16 (dp[1][1] + triangle[2][1])
    #     [2][2] = 15 (dp[1][1] + triangle[2][2])
    answer = max(dp[-1])

    return answer

if __name__ == "__main__":
    print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]))