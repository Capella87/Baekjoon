# 백준 1463번 문제 : 1로 만들기
# https://www.acmicpc.net/problem/1463
# 알고리즘 분류 : 다이나믹 프로그래밍

# 복습 필요

x = int(input())
arr = [0] * (x + 1)

for i in range(2, x + 1):
    arr[i] = arr[i - 1] + 1 # 1을 빼는 경우
    if i % 2 == 0:
        arr[i] = min(arr[i], arr[i // 2] + 1) # 2로 나누어 떨어지는 경우
    if i % 3 == 0:
        arr[i] = min(arr[i], arr[i // 3] + 1) # 3으로 나누어 떨어지는 경우
print(arr[x])
