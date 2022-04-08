# 백준 12015번 문제 : 가장 긴 증가하는 부분 수열 2
# https://www.acmicpc.net/problem/12015
# 알고리즘 분류 : 이분 탐색, 가장 긴 증가하는 부분 수열: o(n log n)

import bisect
import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split(' ')))
lis = [0] * n
last_pos = 0

lis[0] = arr[0]

for i in range(1, n):
    if lis[last_pos] < arr[i]:
        last_pos += 1
        lis[last_pos] = arr[i]
    else:  # bisect_left is a lower bound implementation in Python.
        lis[bisect.bisect_left(lis, arr[i], 0, last_pos)] = arr[i]
print(last_pos + 1)
