# 백준 5648번 문제 : 역원소 정렬
# https://www.acmicpc.net/problem/5648
# 알고리즘 분류 : 정렬

import sys

def reverse_number(a: str) -> int:
    rt = 0
    for i in range(len(a) - 1, -1, -1):
        rt = rt * 10 + int(a[i])
    return rt

lines = sys.stdin.readlines()
first_line = lines[0].rstrip().split(' ')
lines = lines[1:]
n, numbers = first_line[0], first_line[1:]
# Pythonic way: [inner loop result] [outer loop] [inner loop]
numbers += [item for line in lines for item in line.strip().split()]
rt = [reverse_number(item) for item in numbers]
rt.sort()

for i in rt:
    sys.stdout.write(f'{i}\n')
