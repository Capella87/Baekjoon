# 백준 1302번 문제 : 베스트셀러
# https://www.acmicpc.net/problem/1302
# 알고리즘 분류 : 자료 구조, 문자열, 정렬, 집합과 맵, 해시를 사용한 집합과 맵

import sys

n = int(sys.stdin.readline())
dct = {}

for i in range(n):
    target = sys.stdin.readline().strip()
    if dct.get(target, None) is None:
        dct[target] = 1
    else:
        dct[target] += 1
arr = []
for k in dct.keys():
    arr.append((dct[k], k))
arr2 = sorted(arr, key=lambda x: (-x[0], x[1]))
sys.stdout.write(f'{arr2[0][1]}\n')
