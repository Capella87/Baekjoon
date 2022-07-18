# 백준 15650번 문제 : N과 M (2)
# https://www.acmicpc.net/problem/15650
# 알고리즘 분류 : 백트래킹

import sys

n, m = map(int, sys.stdin.readline().split(' '))
is_selected = [0 for i in range(0, n)]
selection = [0 for i in range(0, m)]

def backtracking(selcount):
    global n, m
    if selcount == m:
        print(' '.join(map(str, selection)))
        return
    else:
        for i in range(0, n):
            if is_selected[i] == False and (selcount == 0 or selection[selcount - 1] < i + 1):
                is_selected[i] = True
                selection[selcount] = i + 1
                backtracking(selcount + 1)
                is_selected[i] = False

backtracking(0)
