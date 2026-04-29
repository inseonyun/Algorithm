def solution(tickets):
    answer = ["ICN"]
    checked = [False] * len(tickets)

    tickets.sort()

    def dfs(current):
        if len(answer) == len(tickets) + 1:
            return True

        for idx in range(len(tickets)):
            dep, arr = tickets[idx][0], tickets[idx][1]

            if not checked[idx] and dep == current:
                answer.append(arr)
                checked[idx] = True

                if dfs(arr):
                    return True

                answer.pop()
                checked[idx] = False

        return False

    dfs("ICN")

    return answer

if __name__ == '__main__':
    print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL", "SFO"]]))
