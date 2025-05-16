# 백준 6064번 문제 : 카잉 달력
# https://www.acmicpc.net/problem/6064
# 알고리즘 분류 : 수학, 브루트포스 알고리즘, 정수론, 중국인의 나머지 정리

import sys

def gcd(a: int, b: int) -> int:
    while b:
        a, b = b, a % b
    return a

t = int(sys.stdin.readline())
while t > 0:
    t -= 1
    result = 0
    target = 0
    m, n, x, y = map(int, sys.stdin.readline().strip().split())
    mx = m * n // gcd(m, n)
    if y == n:
        y = 0
    
    for i in range(0, n):
        target = result % n
        if target == y:
            break
        result += m
        if result > mx:
            result = -1
            break
    sys.stdout.write(f'{result}\n')
