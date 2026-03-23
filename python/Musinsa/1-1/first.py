from xxlimited_35 import Null


def solve():
    B, Q = map(int, input().strip().split(","))

    brands = {}

    for _ in range(B):
        brand_name, N = input().strip().split(",")
        N = int(N)

        sizes = []
        for j in range(N):
            size_name, H_min, H_max, C_min, C_max, W_min, W_max = input().strip().split(",")
            H_min, H_max, C_min, C_max, W_min, W_max = int(H_min), int(H_max), int(C_min), int(C_max), int(W_min), int(W_max)
            sizes.append((size_name, H_min, H_max, C_min, C_max, W_min, W_max))

        brands[brand_name] = sizes

    answers = []
    for _ in range(Q):
        want_brand, H, C, W = input().strip().split(",")
        H, C, W = int(H), int(C), int(W)

        if want_brand not in brands:
            answers.append(f"{want_brand}, UNKNOWN")
            continue

        sizes = brands[want_brand]

        recommended = Null
        for size_name, h_min, h_max, c_min, c_max, w_min, w_max in sizes:
            if h_min <= H <= h_max and c_min <= C <= c_max and w_min <= W <= w_max:
                recommended = size_name
                break

        if recommended is not Null:
            answers.append(f"{want_brand}, {recommended}")
            continue

        first_size = sizes[0]
        last_size = sizes[-1]

        _, first_h_min, _, first_C_min, _, first_W_min, _ = first_size
        _, _, last_h_max, _, last_C_max, _, last_W_max = last_size

        if H > last_h_max and C > last_C_max and W > last_W_max:
            result = "UP"
        elif H < first_h_min and C < first_C_min and W < first_W_min:
            result = "DOWN"
        else:
            result = "MISMATCH"

        answers.append(f"{want_brand}, {result}")

    print('\n'.join(answers))

if __name__ == "__main__":
    solve()