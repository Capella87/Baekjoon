# 백준 2075번 문제 : N번째 큰 수
# https://www.acmicpc.net/problem/2075
# 알고리즘 분류 : 자료 구조, 정렬, 우선순위 큐

import sys
import heapq

n = int(sys.stdin.readline())
hq = list(map(int, sys.stdin.readline().strip().split()))
heapq.heapify(hq)

for i in range(n - 1):
    temp = list(map(int, sys.stdin.readline().strip().split()))
    for j in temp:
        if hq[0] < j:
            heapq.heappop(hq)
            heapq.heappush(hq, j)

sys.stdout.write(f'{hq[0]}\n')
