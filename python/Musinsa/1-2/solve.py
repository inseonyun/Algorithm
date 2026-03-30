def solve():
    s, r = map(int, input().strip().split(','))

    stores = {}
    for _ in range(s):
        store_id, open_time, close_time, limit = map(int, input().strip().split(','))
        stores[store_id] = {
            "open_time": open_time,
            "close_time": close_time,
            "limit": limit,
            "stock": {},
            "reserve_count": {}
        }

    for _ in range(s):
        inputs = input().strip().split(',')
        store_id = int(inputs[0])

        stocks = {}
        if inputs[1] != "-":
            for item in inputs[1:]:
                prod, quantity = item.strip().split(':')
                quantity = int(quantity)
                stocks[prod] = quantity

        stores[store_id]["stock"] = stocks

    answers = []
    success_count = 0
    for _ in range(r):
        request, store_id, prod_id, quantity, time = input().strip().split(',')
        request, store_id, quantity = int(request), int(store_id), int(quantity)
        hour, minute = map(int, time.split(':'))

        # 스토어 존재 여부
        if store_id not in stores:
            answers.append(f"{request},FAIL,STORE")
            continue

        # 운영 시간 외
        if not (stores[store_id]["open_time"] <= hour < stores[store_id]["close_time"]):
            answers.append(f"{request},FAIL,TIME")
            continue

        # 해당 시간대 픽업 한도 초과
        if stores[store_id]["reserve_count"].get(hour, 0) >= stores[store_id]["limit"]:
            answers.append(f"{request},FAIL,FULL")
            continue

        # 재고 부족
        if stores[store_id]["stock"][prod_id] < quantity:
            answers.append(f"{request},FAIL,STOCK")
            continue

        stores[store_id]["stock"][prod_id] -= quantity
        stores[store_id]["reserve_count"][hour] = stores[store_id]["reserve_count"].get(hour, 0) + 1
        answers.append(f"{request},OK")
        success_count += 1

    for answer in answers:
        print(answer)
    print(success_count)

if __name__ == '__main__':
    solve()
