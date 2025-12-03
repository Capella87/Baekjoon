# 백준 1449번 문제 : 수리승 항공
# https://www.acmicpc.net/problem/1449
# 알고리즘 분류 : 그리디 알고리즘, 정렬

import sys


n, l = map(int, sys.stdin.readline().strip().split())
locations = list(map(int, sys.stdin.readline().strip().split()))
locations.sort()
idx = count = next = 0

while idx < n:
    if next >= locations[idx]:
        idx += 1
        continue
    next = locations[idx] + l - 1
    count += 1
    idx += 1
sys.stdout.write(f'{count}\n')
