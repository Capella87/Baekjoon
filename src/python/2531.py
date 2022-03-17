# 백준 2531번 문제 : 회전 초밥
# https://www.acmicpc.net/problem/2531
# 알고리즘 분류 : 두 포인터

import sys

n, d, k, c = map(int, sys.stdin.readline().split(' '))
conveyor = [int(sys.stdin.readline().strip()) for _ in range(n)]
sushi_count = [0] * 3001
sushi_stat = 0
start = 0
end = begin = k - 1

for i in range(start, end + 1):
    if sushi_count[conveyor[i]] == 0:
        sushi_stat += 1
    sushi_count[conveyor[i]] += 1
if sushi_count[c] == 0:
    sushi_stat += 1
sushi_count[c] += 1
max_sushi = sushi_stat

while True:
    end = (end + 1) % n
    if end == begin:
        break

    sushi_count[conveyor[start]] -= 1
    if sushi_count[conveyor[start]] == 0:
        sushi_stat -= 1
    start = (start + 1) % n
    sushi_count[conveyor[end]] += 1
    if sushi_count[conveyor[end]] == 1:
        sushi_stat += 1
    if max_sushi < sushi_stat:
        max_sushi = sushi_stat

print(max_sushi)
