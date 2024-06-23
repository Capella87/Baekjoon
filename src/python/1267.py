# 백준 1267번 문제 : 핸드폰 요금
# https://www.acmicpc.net/problem/1267
# 알고리즘 분류 : 수학, 사칙연산

import sys


n = int(sys.stdin.readline())
yeongsik, minsik = 0, 0
history = list(map(int, sys.stdin.readline().split(' ')))
for i in history:
    yeongsik += (i // 30 + 1) * 10
    minsik += (i // 60 + 1) * 15

if yeongsik < minsik:
    sys.stdout.write(f'Y {yeongsik}')
elif yeongsik == minsik:
    sys.stdout.write(f'Y M {yeongsik}')
else:
    sys.stdout.write(f'M {minsik}')
