# 백준 10610번 문제 : 30
# https://www.acmicpc.net/problem/10610
# 알고리즘 분류 : 수학, 문자열, 그리디 알고리즘, 정렬, 정수론

import sys

digit_count = [0 for i in range(10)]
num = sys.stdin.readline().strip('\n')
for i in num:
    digit_count[int(i)] += 1
tot = 0

if digit_count[0] == 0:
    print(-1)
else:
    for i in range(1, 10):
        tot += digit_count[i] * i
    if tot % 3 != 0:
        print(-1)
    else:
        print(''.join(sorted(num, reverse=True)))
