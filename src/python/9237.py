# 백준 9237번 문제 : 이장님 초대
# https://www.acmicpc.net/problem/9237
# 알고리즘 분류 : 그리디 알고리즘, 정렬

import sys

n = int(sys.stdin.readline())
saplings = list(map(int, sys.stdin.readline().split(' ')))
saplings.sort(reverse=True)

today = 0
days = 0
for i in saplings:
    if today + 1 + i >= days:
        days = today + 1 + i
    today += 1

print(days + 1)
