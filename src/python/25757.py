# 백준 25757번 문제 : 임스와 함께하는 미니게임
# https://www.acmicpc.net/problem/25757
# 알고리즘 분류 : 자료 구조, 문자열, 해시를 사용한 집합과 맵

import sys

temp = sys.stdin.readline().strip().split()

n = int(temp[0])
gametype = temp[1]

requesters = {}
for i in range(n):
    user = sys.stdin.readline().strip()
    requesters[user] = 1

rt = 0
if gametype == 'Y':
    rt = len(requesters)
elif gametype == 'F':
    rt = len(requesters) // 2
else:
    rt = len(requesters) // 3

sys.stdout.write(f'{rt}\n')
