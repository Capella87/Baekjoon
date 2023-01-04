# 백준 11478번 문제 : 서로 다른 부분 문자열의 개수
# https://www.acmicpc.net/problem/11478
# 알고리즘 분류 : 자료 구조, 문자열, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

import sys

arr = list(sys.stdin.readline().strip('\n'))
stri = ''.join(arr)

dicti = dict(map(lambda i, j : (i, j), arr, arr))
dicti[stri] = stri

le = len(stri)
for i in range(2, le):
    for j in range(le - i + 1):
        dicti[stri[j:j + i]] = stri[j:j + i]

print(len(dicti))
