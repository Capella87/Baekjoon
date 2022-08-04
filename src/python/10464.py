# 백준 10464번 문제 : XOR
# https://www.acmicpc.net/problem/10464
# 알고리즘 분류 : 수학

import sys

t = int(sys.stdin.readline())
for i in range(0, t):
    n, m = map(int, sys.stdin.readline().split(' '))

    if n == m:
        print(n)
        continue
    if n % 2 == 1:
        result = [n ^ m, n - 1, (n ^ m) - 1, n]
        print(result[(m - n - 1) % 4])
    else:
        result = [1, m + 1, 0, m]
        print(result[(m - n - 1) % 4])
