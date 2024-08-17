# 백준 16165번 문제 : 걸그룹 마스터 준석이
# https://www.acmicpc.net/problem/16165
# 알고리즘 분류 : 자료 구조, 해시를 사용한 집합과 맵

import sys


n, m = map(int, sys.stdin.readline().strip().split())
groups = {}
entries = {}

for i in range(n):
    group_name = sys.stdin.readline().strip()
    numofmem = int(sys.stdin.readline())
    mems = []
    for j in range(numofmem):
        name = sys.stdin.readline().strip()
        entries[name] = group_name
        mems.append(name)
    mems.sort()
    groups[group_name] = mems
for i in range(m):
    q = sys.stdin.readline().strip()
    tpe = int(sys.stdin.readline())
    if tpe == 1:
        sys.stdout.write(f'{entries[q]}\n')
        continue
    le = len(groups[q])
    target = groups[q]
    for j in range(le):
        sys.stdout.write(f'{target[j]}\n')
