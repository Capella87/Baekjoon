# 백준 13305번 문제 : 주유소
# https://www.acmicpc.net/problem/13305
# 알고리즘 분류 : 그리디 알고리즘

import sys

n = int(sys.stdin.readline())
req_liters = list(map(int, sys.stdin.readline().split(' ')))
stations = list(map(int, sys.stdin.readline().split(' ')))

min_price = stations[0]
cost = stations[0] * req_liters[0]

for i in range(1, n - 1):
    if min_price > stations[i]:
        min_price = stations[i]
    cost += min_price * req_liters[i]
    
print(cost)
