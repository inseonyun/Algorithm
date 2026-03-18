# list insert
insert_li = [1, 2, 3]
insert_li.append(4)  # 맨 뒤에 원소 추가
insert_li.insert(0, 0)  # 특정 인덱스에 원소 추가
insert_li + [5]  # 원 배열에는 반영 X, 원소 5가 추가된 리스트 반환

# list delete
delete_li = [1, 2, 3, 4, 5]
delete_li.remove(3)  # 값 제거, 여러 개일 경우 가장 앞에 인덱스의 값 제거
del delete_li[-1]  # 마지막 원소 제거, 인덱스 제거

# list sort
sort_li = [2, 3, 1, 5, 2]
sorted(sort_li)  # 정렬된 리스트 반환, 원 배열에 반영 X
sort_li.sort()  # 원 배열 정렬 반영

# list reverse
reverse_li = [1, 2, 3, 4, 5]
reverse_li[::-1]
reversed(reverse_li)  # 리버스된 리스트 반환, 원 배열에 반영 X
reverse_li.reverse()  # 원 배열 리버스 반영

# list comprehension
li = [i for i in range(1, 11) if i % 2 == 0]
print(li)
