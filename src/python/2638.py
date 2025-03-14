# 백준 2638번 문제 : 치즈
# https://www.acmicpc.net/problem/2638
# 알고리즘 분류 : 구현, 그래프 이론, 그래프 탐색, 시뮬레이션, 너비 우선탐색, 깊이 우선 탐색

import sys
from collections import deque

xdir = [0, 1, 0, -1]
ydir = [1, 0, -1, 0]

def bfs(mp: list[list[int]],
        smap: list[list[int]],
        targets: list[tuple[int, int]],
        rows: int,
        columns: int) -> list[tuple[int, int]]:
    q = deque(targets)
    rt = []
    for i in targets:
        smap[i[0]][i[1]] = 0
    while len(q) > 0:
        x, y = deque.popleft(q)

        for i in range(4):
            nx = x + xdir[i]
            ny = y + ydir[i]
            if nx < 0 or ny < 0 or nx >= rows or ny >= columns:
                continue
            if smap[nx][ny] == -1 and mp[nx][ny] == 0:
                smap[nx][ny] = 0
                deque.append(q, (nx, ny))
            elif mp[nx][ny] == 1:
                smap[nx][ny] = 1 if smap[nx][ny] == -1 else smap[nx][ny] + 1
                if smap[nx][ny] > 1:
                    mp[nx][ny] = 0
                    rt.append((nx, ny))
    return rt

n, m = map(int, sys.stdin.readline().strip().split(' '))
cheesemap = []
statusmap = []

for i in range(n):
    row = list(map(int, sys.stdin.readline().strip().split(' ')))
    cheesemap.append(row)
    t = [-1] * m
    statusmap.append(t)
tgts = [(0, 0)]
hrs = 0
while len(tgts):
    hrs += 1
    tgts = bfs(cheesemap, statusmap, tgts, n, m)
hrs -= 1
sys.stdout.write(f'{hrs}\n')
