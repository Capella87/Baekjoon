# 백준 2910번 문제 : 빈도 정렬
# https://www.acmicpc.net/problem/2910
# 알고리즘 분류 : 자료 구조, 정렬, 해시를 사용한 집합과 맵

import sys


n, c = map(int, sys.stdin.readline().split(' '))
numbers = list(map(int, sys.stdin.readline().split(' ')))
freq = {}
for i in range(n):
    freq[numbers[i]] = freq.get(numbers[i], 0) + 1
result = dict(sorted(freq.items(), key=lambda item: item[1], reverse=True))
for k, v in result.items():
    for _ in range(v):
        sys.stdout.write(f'{k} ')
sys.stdout.write('\n')
