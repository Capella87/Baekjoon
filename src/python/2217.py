# 백준 2217번 문제 : 로프
# https://www.acmicpc.net/problem/2217
# 알고리즘 분류 : 수학, 그리디 알고리즘, 정렬

import sys

n = int(input())
ropes = [int(sys.stdin.readline().strip()) for _ in range(n)]
# Use readline to be faster.
# strip() is to remove '\n'

ropes.sort() # Use reverse=True to sort descending.
max_weight = 0

for i in range(n):
    temp = ropes[i] * (n - i)
    if max_weight < temp: max_weight = temp
print(max_weight)
