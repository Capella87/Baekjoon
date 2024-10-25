# 백준 1138번 문제 : 한 줄로 서기
# https://www.acmicpc.net/problem/1138
# 알고리즘 분류 : 구현, 그리디 알고리즘

import sys


n = int(sys.stdin.readline())
arr = map(int, sys.stdin.readline().split(' '))
answer = [0] * n
height = 1
zero_begin_idx = 0
for i in arr:
    cur = zero_begin_idx
    relative_cur = 0
    while cur < n:
        if answer[cur] == 0:
            if relative_cur == i:
                break
            relative_cur += 1
        cur += 1
    answer[cur] = height
    while zero_begin_idx < n and answer[zero_begin_idx] != 0:
        zero_begin_idx += 1
    height += 1
    
for i in answer:
    sys.stdout.write(f'{i} ')
sys.stdout.write('\n')
