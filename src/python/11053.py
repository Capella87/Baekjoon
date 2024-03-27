# 백준 11053번 문제 : 가장 긴 증가하는 부분 수열
# https://www.acmicpc.net/problem/11053
# 알고리즘 분류 : 다이나믹 프로그래밍

import sys


def lower_bound(lst: list, start: int, end: int, target: int) -> int:
    if start == end:
        return start

    while start < end:
        cur = (start + end) // 2
        if lst[cur] < target:
            start = cur + 1
        else:
            end = cur

    return end

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
asc_arr = [0] * n
asc_arr[0] = arr[0]
asc_idx = 0

for i in range(1, n):
    if asc_arr[asc_idx] < arr[i]:
        asc_idx += 1
        asc_arr[asc_idx] = arr[i]
    else:
        idx = lower_bound(asc_arr, 0, asc_idx, arr[i])
        asc_arr[idx] = arr[i]

print(asc_idx + 1)
