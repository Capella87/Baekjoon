# 백준 1699번 문제 : 제곱수의 합
# https://www.acmicpc.net/problem/1699
# 알고리즘 분류 : 수학, 다이나믹 프로그래밍

import sys

n = int(sys.stdin.readline())

cache = list(range(n + 1))

for i in range(2, n + 1):
    j = 2
    while (j * j) <= i:
        sq = j * j
        if cache[i] > cache[i - sq] + 1:
            cache[i] = 1 + cache[i - sq]
        j += 1
sys.stdout.write(f'{cache[n]}\n')
