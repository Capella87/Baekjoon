# 백준 5972번 문제 : 택배 배송
# https://www.acmicpc.net/problem/5972
# 알고리즘 분류 : 그래프 이론, 최단 경로, 데이크스트라

import sys
import heapq

n, m = map(int, sys.stdin.readline().strip().split(' '))
barns = [[] for _ in range(n + 1)]
visitmap = [None] * (n + 1)

for i in range(m):
    src, dest, stovers = map(int, sys.stdin.readline().strip().split(' '))
    barns[src].append((dest, stovers))
    barns[dest].append((src, stovers))

hq = []
visitmap[1] = 0
heapq.heappush(hq, (0, 1))

while len(hq) > 0:
    stv, brn = heapq.heappop(hq)

    for nxt in barns[brn]:
        if visitmap[nxt[0]] is None or (stv + nxt[1]) < visitmap[nxt[0]]:
            visitmap[nxt[0]] = stv + nxt[1]
            heapq.heappush(hq, (stv + nxt[1], nxt[0]))

sys.stdout.write(f'{visitmap[n]}\n')
