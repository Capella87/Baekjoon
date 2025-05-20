# 백준 4386번 문제 : 별자리 만들기
# https://www.acmicpc.net/problem/4386
# 알고리즘 분류 : 그래프 이론, 최소 스패닝 트리

import sys
import heapq
import math

n = int(sys.stdin.readline())
arr = [(0, 0)]
for i in range(n):
    x, y = map(float, sys.stdin.readline().split())
    arr.append((x, y))

hq = []
visitboard = [False] * (n + 1)
rt = 0.0

heapq.heappush(hq, (0.0, 1))
while hq:
    distance, star = heapq.heappop(hq)

    if visitboard[star]:
        continue
    visitboard[star] = True
    rt += distance

    for i in range(1, n + 1):
        if not visitboard[i]:
            d = math.sqrt(math.pow(arr[i][0] - arr[star][0], 2) + math.pow(arr[i][1] - arr[star][1], 2))
            heapq.heappush(hq, (d, i))
sys.stdout.write(f'{rt:.2f}\n')
