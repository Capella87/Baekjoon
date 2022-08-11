# 백준 15652번 문제 : N과 M (4)
# https://www.acmicpc.net/problem/15652
# 알고리즘 분류 : 백트래킹

import sys

n, m = map(int, sys.stdin.readline().split(' '))
result = [0 for i in range(m)]

def backtracking(count, min):
    global n, m
    if count == m:
        print(' '.join(map(str, result)))
        return
    for i in range(min, n):
        result[count] = i + 1
        backtracking(count + 1, i)

backtracking(0, 0)
