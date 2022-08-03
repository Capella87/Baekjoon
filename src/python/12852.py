# 백준 12852번 문제 : 1로 만들기 2
# https://www.acmicpc.net/problem/12852
# 알고리즘 분류 : 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색

import sys

n = int(sys.stdin.readline())

cache = [0] * (n + 1)
prev_num = [0] * (n + 1)

for i in range(2, n + 1):
    prev_num[i] = i - 1
    cache[i] = cache[i - 1] + 1

    if i % 2 == 0:
        rt = i // 2
        if cache[i] > cache[rt] + 1:
            prev_num[i] = rt
            cache[i] = cache[rt] + 1
    if i % 3 == 0:
        rt = i // 3
        if cache[i] > cache[rt] + 1:
            prev_num[i] = rt
            cache[i] = cache[rt] + 1

print(cache[n])
print(n, end=' ')
while n != 1:
    print(prev_num[n], end=' ')
    n = prev_num[n]
print()
