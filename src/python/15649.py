# 백준 15649번 문제 : N과 M (1)
# https://www.acmicpc.net/problem/15649
# 알고리즘 분류 : 백트래킹

import sys

n, m = map(int, sys.stdin.readline().split(' '))
is_checked = [False for i in range(n)]
result = [0 for i in range(m)]

def backtracking(count):
    global n, m
    if count == m:
        print(' '.join(map(str, result)))
        return
    for i in range(n):
        if is_checked[i] == False:
            is_checked[i] = True
            result[count] = i + 1
            backtracking(count + 1)
            is_checked[i] = False

backtracking(0)
