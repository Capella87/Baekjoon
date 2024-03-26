# 백준 2293번 문제 : 동전 1
# https://www.acmicpc.net/problem/2293
# 알고리즘 분류 : 다이나믹 프로그래밍

import sys

n, k = map(int, sys.stdin.readline().split())
cache = [1] + [0] * k

for i in range(n):
    coin = int(sys.stdin.readline())
    for j in range(coin, k + 1):
        cache[j] += cache[j - coin]

print(cache[k])
