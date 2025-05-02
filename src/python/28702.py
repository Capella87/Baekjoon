# 백준 28702번 문제 : FizzBuzz
# https://www.acmicpc.net/problem/28702
# 알고리즘 분류 : 수학, 문자열

import sys

arr = [sys.stdin.readline().strip() for i in range(3)]

bn = 0
idx = -1
for i in range(3):
    if arr[i].isnumeric():
        bn = int(arr[i])
        idx = i
        break

ans_number = bn + (3 - idx)
is_detected = False

if ans_number % 3 == 0:
    sys.stdout.write('Fizz')
    is_detected = True
if ans_number % 5 == 0:
    sys.stdout.write('Buzz')
    is_detected = True
if not is_detected:
    sys.stdout.write(f'{ans_number}')
sys.stdout.write('\n')
