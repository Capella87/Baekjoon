# 백준 23757번 문제 : 아이들과 선물 상자
# https://www.acmicpc.net/problem/23757
# 알고리즘 분류 : 자료 구조, 우선순위 큐

import sys
import heapq

n, m = map(int, sys.stdin.readline().strip().split())
gifts = list(map(int, sys.stdin.readline().strip().split()))
for i in range(n):
    gifts[i] *= -1
kids = list(map(int, sys.stdin.readline().strip().split()))
heapq.heapify(gifts)
is_invalid = False

for kid in kids:
    if len(gifts) == 0 or kid > -gifts[0]:
        is_invalid = True
        break
    gft = heapq.heappop(gifts) * -1
    if gft - kid > 0:
        heapq.heappush(gifts, -(gft - kid))
        
sys.stdout.write(f'{"0" if is_invalid else "1"}\n')
