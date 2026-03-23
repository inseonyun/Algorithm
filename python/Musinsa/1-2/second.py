def solve():
    # S: 스토어 수, R: 요청 수
    S, R = map(int, input().strip().split(","))

    stores = {}

    # 스토어 정보
    # N_i:스토어 id
    # L_i:오픈 시간
    # R_i:마감 시간
    # M_i:시간당 픽업 한도
    for _ in range(S):
        N_i, L_i, R_i, M_i = map(int, input().strip().split(","))

        stores[N_i] = {
            "open": L_i,
            "close": R_i,
            "limit": M_i,
            "stock": {},
            "reserve_count": {}
        }

    # 스토어별 재고 정보
    for _ in range(S):
        input_str = input().strip().split(",")
        store_id = int(input_str[0])

        stock = {}

        if input_str[1] != "-":
            for item in input_str[1:]:
                product_id, quantity = item.split(":")
                stock[product_id] = int(quantity)

        stores[store_id]["stock"] = stock

    results = []
    success_count = 0

    # 요청 처리
    # P_k:요청 id
    # N_k:스토어 id
    # X_k:상품 id
    # A_k:수량
    # T_k:희망 시간
    for _ in range(R):
        P_k, N_k, X_k, A_k, T_k = input().strip().split(",")
        P_k = int(P_k)
        N_k = int(N_k)
        A_k = int(A_k)

        hour, minute = map(int, T_k.strip().split(":"))

        if N_k not in stores:
            results.append(f"{P_k},FAIL,STORE")
            continue

        if not (stores[N_k]["open"] <= hour < stores[N_k]["close"] ):
            results.append(f"{P_k},FAIL,TIME")
            continue

        c_time = stores[N_k]["reserve_count"].get(hour, 0)
        if c_time >= stores[N_k]["limit"]:
            results.append(f"{P_k},FAIL,TIME")
            continue

        if stores[N_k]["stock"].get(X_k, 0) < A_k:
            results.append(f"{P_k},FAIL,STOCK")
            continue

        stores[N_k]["stock"][X_k] -= A_k
        stores[N_k]["reserve_count"][hour] = c_time + 1
        results.append(f"{P_k},OK")
        success_count += 1

    print("\n".join(results))
    print(success_count)

if __name__ == "__main__":
    solve()
