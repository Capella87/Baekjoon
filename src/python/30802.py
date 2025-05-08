# 백준 30802번 문제 : 웰컴 키트
# https://www.acmicpc.net/problem/30802
# 알고리즘 분류 : 수학, 구현, 사칙연산

import math
import sys

n = int(sys.stdin.readline())
tsizes = list(map(int, sys.stdin.readline().strip().split(' ')))
t, p = map(int, sys.stdin.readline().strip().split(' '))
req_t = req_bp = req_op = 0

for i in tsizes:
    req_t += math.ceil(i / t)
req_bp = n // p
req_op = n % p

sys.stdout.write(f'{req_t}\n{req_bp} {req_op}\n')
