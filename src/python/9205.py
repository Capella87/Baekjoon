# 백준 9205번 문제 : 맥주 마시면서 걸어가기
# https://www.acmicpc.net/problem/9205
# 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

import sys
from collections import deque

t = int(sys.stdin.readline())
while t > 0:
    t -= 1
    n = int(sys.stdin.readline())
    mp = []
    mp.append(tuple(map(int, sys.stdin.readline().strip().split(' '))))
    for i in range(n):
        mp.append(tuple(map(int, sys.stdin.readline().strip().split(' '))))
    mp.append(tuple(map(int, sys.stdin.readline().strip().split(' '))))
    isVisited = [False] * (n + 2)
    isVisited[0] = True
    q = deque([0])
    while len(q) > 0:
        curIdx = q.popleft()
        if curIdx == n + 1:
            break
        for i in range(curIdx - 1, -1, -1):
            if not isVisited[i]:
                dist = abs(mp[i][0] - mp[curIdx][0]) + abs(mp[i][1] - mp[curIdx][1])
                if dist <= 1000:
                    isVisited[i] = True
                    q.append(i)
        for i in range(curIdx + 1, n + 2):
            if not isVisited[i]:
                dist = abs(mp[i][0] - mp[curIdx][0]) + abs(mp[i][1] - mp[curIdx][1])
                if dist <= 1000:
                    isVisited[i] = True
                    q.append(i)
    if not isVisited[n + 1]:
        sys.stdout.write('sad\n')
    else:
        sys.stdout.write('happy\n')
