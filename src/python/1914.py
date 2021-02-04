# 백준 1914번 문제 : 하노이 탑
# https://www.acmicpc.net/problem/1914
# 알고리즘 분류 : 임의 정밀도 / 큰 수 연산, 재귀

import math

def hanoiTower(num, src, via, dest):
    if num == 1:
        print(src, dest)
    else:
        hanoiTower(num - 1, src, dest, via)
        print(src, dest)
        hanoiTower(num - 1, via, src, dest)

n = int(input())
print(2**n - 1)
if n <= 20:
    hanoiTower(n, 1, 2, 3)