def solve():
    b, q = map(int, input().strip().split(","))

    brands = {}
    for _ in range(b):
        brand_name, size_quantity = input().strip().split(",")
        size_quantity = int(size_quantity)

        sizes = []
        for _ in range(size_quantity):
            size_name, h_min, h_max, c_min, c_max, w_min, w_max = input().strip().split(",")
            h_min, h_max, c_min, c_max, w_min, w_max = int(h_min), int(h_max), int(c_min), int(c_max), int(w_min), int(
                w_max)
            sizes.append((size_name, h_min, h_max, c_min, c_max, w_min, w_max))

        brands[brand_name] = sizes

    answers = []
    for _ in range(q):
        s_want, h, c, w = input().strip().split(",")
        h, c, w = int(h), int(c), int(w)

        # 브랜드 탐색
        if s_want not in brands:
            answers.append(f"{s_want},UNKNOWN")
            continue

        # 사이즈 탐색
        small_size = brands[s_want][0]
        large_size = brands[s_want][-1]

        # DOWN 조건
        if small_size[1] > h and small_size[3] > c and small_size[5] > w:
            answers.append(f"{s_want},DOWN")
            continue

        # UP 조건
        if large_size[1] < h and large_size[3] < c and large_size[5] < w:
            answers.append(f"{s_want},UP")
            continue

        correct = False
        for size_name, h_min, h_max, c_min, c_max, w_min, w_max in brands[s_want]:
            # 사이즈 일치
            if h_min <= h <= h_max and c_min <= c <= c_max and w_min <= w <= w_max:
                answers.append(f"{s_want},{size_name}")
                correct = True
                break
        if correct:
            continue

        # 사이즈 미일치
        answers.append(f"{s_want},MISMATCH")

    for answer in answers:
        print(answer)


if __name__ == "__main__":
    solve()
