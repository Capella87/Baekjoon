# 백준 1238번 문제 : 파티
# https://www.acmicpc.net/problem/1238
# 알고리즘 분류 : 그래프 이론, 최단 경로, 데이크스트라

import sys
import heapq

n, m, x = map(int, sys.stdin.readline().strip().split(' '))
villages = [[] for _ in range(n + 1)]
rttboard = [0 for _ in range(n + 1)]

for i in range(m):
    src, dest, hrs = map(int, sys.stdin.readline().strip().split(' '))
    villages[src].append((dest, hrs))


def calc_traveltime(src, dest, is_venue = False):
    visitboard = [-1 for _ in range(n + 1)]
    if is_venue:
        _ = dijkstra(src, -1, visitboard)
        for j in range(1, n + 1):
            if j == src:
                continue
            rttboard[j] += visitboard[j]
    else:
        rttboard[src] += dijkstra(src, dest, visitboard)


def dijkstra(src, dest, visitboard: list):
    hq = [(0, src)]

    while len(hq):
        elapsed, cur = heapq.heappop(hq)
        if cur == dest:
            continue
        for i in villages[cur]:
            if visitboard[i[0]] == -1 or (elapsed + i[1]) < visitboard[i[0]]:
                visitboard[i[0]] = elapsed + i[1]
                heapq.heappush(hq, (visitboard[i[0]], i[0]))
    return visitboard[dest]

for i in range(1, n + 1):
    if i == x:
        calc_traveltime(i, -1, True)
    else:
        calc_traveltime(i, x)
rt = 0
student = x
for i in range(1, n + 1):
    if i == x:
        continue
    if student == x or rt < rttboard[i]:
        student = i
        rt = rttboard[i]

sys.stdout.write(f'{rt}\n')
