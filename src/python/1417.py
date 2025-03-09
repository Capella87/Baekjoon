# 백준 1417번 문제 : 국회의원 선거
# https://www.acmicpc.net/problem/1417
# 알고리즘 분류 : 수학, 사칙연산

import sys

def getmaxidx(arr):
    idx = len(arr) - 1
    for i in range(len(arr) - 1, -1, -1):
        if arr[idx] < arr[i]:
            idx = i
    return idx

n = int(sys.stdin.readline().strip())
fr = int(sys.stdin.readline().strip())
arr = []
count = 0

if n > 1:
    for i in range(n - 1):
        arr.append(int(sys.stdin.readline().strip()))
    arr.sort()
    idx = getmaxidx(arr)
    while arr[idx] >= fr:
        count += 1
        fr += 1
        arr[idx] -= 1
        idx = getmaxidx(arr)

sys.stdout.write(f'{count}\n')
