# 백준 31403번 문제 : A + B - C
# https://www.acmicpc.net/problem/31403
# 알고리즘 분류 : 수학, 문자열, 사칙연산

import sys

a = sys.stdin.readline().strip()
b = sys.stdin.readline().strip()
c = sys.stdin.readline().strip()

result = int(a) + int(b) - int(c)
sys.stdout.write(f'{result}\n')
ab = a + b
result = int(ab) - int(c)
sys.stdout.write(f'{result}\n')
