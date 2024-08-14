# 백준 13414번 문제 : 수강신청
# https://www.acmicpc.net/problem/13414
# 알고리즘 분류 : 구현, 자료 구조, 해시를 사용한 집합과 맵

import sys


k, n = map(int, sys.stdin.readline().strip().split())
entries = {}
lst = []

for i in range(n):
    stu_id = sys.stdin.readline().strip()
    r = entries.get(stu_id, None)
    lst.append(stu_id)
    if r is not None:
        lst[r] = '0'
    entries[stu_id] = len(lst) - 1
j, i = 0, 0
l = len(lst)
while i < l and j < k:
    if lst[i] != '0':
        sys.stdout.write(f'{lst[i]}\n')
        j += 1
    i += 1
