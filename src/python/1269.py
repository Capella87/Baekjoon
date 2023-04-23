# 백준 1269번 문제 : 대칭 차집합
# https://www.acmicpc.net/problem/1269
# 알고리즘 분류 : 자료 구조, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

import sys

a, b = map(int, sys.stdin.readline().strip('\n').split(' '))

seta = set(sys.stdin.readline().strip('\n').split(' '))
setb = set(sys.stdin.readline().strip('\n').split(' '))

print(len((seta - setb) | (setb - seta)))
