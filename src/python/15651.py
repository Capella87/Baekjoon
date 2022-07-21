# 백준 15651번 문제 : N과 M (3)
# https://www.acmicpc.net/problem/15651
# 알고리즘 분류 : 백트래킹

import sys

n, m = map(int, sys.stdin.readline().split(' '))
result = [0 for i in range(m)]

def backtracking(count):
    global n, m
    if count == m:
        print(' '.join(map(str, result)))
        return
    for i in range(n):
        result[count] = i + 1
        backtracking(count + 1)

backtracking(0)
