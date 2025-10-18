# 백준 2257번 문제 : 화학식량
# https://www.acmicpc.net/problem/2257
# 알고리즘 분류 : 자료 구조, 문자열, 스택

import sys
from collections import deque

target = sys.stdin.readline().strip()

weights = {
    'H': 1,
    'C': 12,
    'O': 16
}

temp = 0
total = 0
subtotal = 0
stk = deque()

for i in target:
    if i == '(':
        subtotal += temp
        stk.appendleft(subtotal)
        subtotal = temp = 0
    elif i == ')':
        subtotal += temp
        temp = subtotal
        subtotal = stk.popleft()
    elif ord('2') <= ord(i) <= ord('9'):
        temp *= int(i)
        subtotal += temp
        temp = 0
    else:
        subtotal += temp
        temp = weights[i]
while len(stk):
    total += stk.popleft()
total += subtotal + temp

sys.stdout.write(f'{total}\n')
