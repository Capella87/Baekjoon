# 백준 27497번 문제 : 알파벳 블록
# https://www.acmicpc.net/problem/27497
# 알고리즘 분류 : 자료 구조, 문자열, 스택, 덱

import sys
from collections import deque

n = int(sys.stdin.readline())
direction_stk = deque()
strstk = deque()
dr = 0 # 1 for left, 2 for right
for i in range(n):
    inpt = sys.stdin.readline().split()
    command = int(inpt[0])
    ch = '' if len(inpt) == 1 else inpt[1]

    if dr > 0 and command < 3:
        direction_stk.appendleft(dr)
    if command == 1:
        dr = 1
        strstk.append(ch)
    elif command == 2:
        dr = 2
        strstk.appendleft(ch)
    elif len(strstk) > 0:
        if dr == 1:
            strstk.pop()
        elif dr == 2:
            strstk.popleft()

        if len(direction_stk) > 0:
            dr = direction_stk.popleft()
result = ''.join(list(strstk))

sys.stdout.write(f'{result if len(result) > 0 else "0"}\n')
