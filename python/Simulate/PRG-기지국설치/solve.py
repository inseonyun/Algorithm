import math


def solution(n, stations, w):
    answer = 0

    coverage = 2 * w + 1

    start = 1

    for station in stations:
        left = station - w
        right = station + w

        # 현재 기지국이 커버하기 전까지 비어 있는 구간
        end = left - 1

        if start <= end:
            length = end - start + 1
            answer += math.ceil(length / coverage)

        # 다음으로 확인해야 할 시작 위치
        start = right + 1

    # 마지막 기지국 이후 남은 구간
    if start <= n:
        length = n - start + 1
        answer += math.ceil(length / coverage)

    return answer


if __name__ == '__main__':
    print(solution(16, [9], 2))
