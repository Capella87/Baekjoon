# 백준 7795번 문제 : 먹을 것인가 먹힐 것인가
# https://www.acmicpc.net/problem/7795
# 알고리즘 분류 : 정렬, 이분 탐색, 두 포인터

import sys

def lower_bound(arr: list, target: int) -> int:
    left, right = 0, len(arr) - 1

    while left < right:
        mid = (left + right) // 2
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid
    return right


t = int(sys.stdin.readline())
while t > 0:
    n, m = map(int, sys.stdin.readline().strip().split())
    a = list(map(int, sys.stdin.readline().strip().split()))
    b = list(map(int, sys.stdin.readline().strip().split()))
    a.sort()
    b.sort()
    result = 0

    for i in a:
        idx = lower_bound(b, i)
        if i > b[idx]:
            result += idx + 1
        else:
            result += idx
    sys.stdout.write(f'{result}\n')
    t -= 1
