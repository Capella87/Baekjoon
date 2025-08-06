# 백준 11689번 문제 : 평범한 배낭
# https://www.acmicpc.net/problem/12865
# 알고리즘 분류 : 다이나믹 프로그래밍, 배낭 문제

import sys

n, k = map(int, sys.stdin.readline().strip('\n'))

weight = []
value = []
cache = [0 for i in range(k + 1)]

for i in range(n):
    w, v = map(int, sys.stdin.readline().strip('\n'))
    weight.append(w)
    value.append(v)

for i in range(n):
    for j in range(0, i):
        