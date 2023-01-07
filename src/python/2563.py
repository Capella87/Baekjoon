# 백준 2563번 문제 : 색종이
# https://www.acmicpc.net/problem/2563
# 알고리즘 분류 : 구현

import sys

arr = [[0 for i in range(100)] for j in range(100)]

total = 0
n = int(sys.stdin.readline().strip('\n'))
for i in range(n):
    x, y = map(int, sys.stdin.readline().strip('\n').split(' '))

    xlimit = x + 10 if (x + 10) <= 100 else 100
    ylimit = y + 10 if (y + 10) <= 100 else 100
    for j in range(x, xlimit):
        for k in range(y, ylimit):
            if arr[j][k] == 0:
                arr[j][k] = 1
                total += 1
print(total)
