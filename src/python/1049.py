# 백준 1049번 문제 : 기타줄
# https://www.acmicpc.net/problem/1049
# 알고리즘 분류 : 수학, 그리디 알고리즘

import sys

n, m = map(int, sys.stdin.readline().split())
guitarstrings1 = []
guitarstrings2 = []
guitarstrings3 = []
for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    guitarstrings1.append(a)
    guitarstrings2.append(b)
    guitarstrings3.append(b * 6)

guitarstrings1.sort()
guitarstrings2.sort()
guitarstrings3.sort()
unitsix = guitarstrings1[0] if guitarstrings1[0] < guitarstrings3[0] else guitarstrings3[0]
leftover = unitsix if unitsix < (guitarstrings2[0] * (n % 6)) else (guitarstrings2[0] * (n % 6))

sys.stdout.write(f'{unitsix * (n // 6) + leftover}\n')
