# 백준 2083번 문제 : 럭비 클럽
# https://www.acmicpc.net/problem/2083
# 알고리즘 분류 : 구현

import sys


while True:
    name, age, weight = sys.stdin.readline().split()
    if name == '#':
        break
    age = int(age)
    weight = int(weight)
    
    sys.stdout.write(f'{name} ')
    sys.stdout.write('Senior\n' if age > 17 or weight >= 80 else 'Junior\n')
