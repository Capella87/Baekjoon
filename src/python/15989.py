# 백준 15989번 문제 : 1, 2, 3 더하기 4
# https://www.acmicpc.net/problem/15989
# 알고리즘 분류 : 다이나믹 프로그래밍

import sys

def init(n: int = 10_000) -> list:
    arr = [0] * (n + 1)
    
    for i in range(1, 4):
        arr[i] = i
    for i in range(4, n + 1):
        arr[i] = 1 + i // 2 + arr[i - 3]
    return arr

t = int(sys.stdin.readline())
cache = init()
while t > 0:
    n = int(sys.stdin.readline())
    sys.stdout.write(f'{cache[n]}\n')
    t -= 1
