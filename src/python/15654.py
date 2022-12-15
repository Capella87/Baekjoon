# 백준 15651번 문제 : N과 M (5)
# https://www.acmicpc.net/problem/15654
# 알고리즘 분류 : 백트래킹

import sys

n, m = map(int, sys.stdin.readline().split(' '))
result = [0 for i in range(m)]
nums = list(map(int, sys.stdin.readline().split(' ')))
nums.sort()
is_selected = [False for i in range(n)]

def backtracking(count):
    global n, m
    if count == m:
        print(' '.join(map(str, result)))
        return
    for i in range(0, n):
        if is_selected[i] == False:
            is_selected[i] = True
            result[count] = nums[i]
            backtracking(count + 1)
            is_selected[i] = False

backtracking(0)
