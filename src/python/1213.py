# 백준 1213번 문제 : 팰린드롬 만들기
# https://www.acmicpc.net/problem/1213
# 알고리즘 분류 : 구현, 그리디 알고리즘, 문자열, 홀짝성

import sys

target = sys.stdin.readline().strip()
ln = len(target)
stat = [0 for _ in range(26)]
a_ord = ord('A')
result = ['A' for _ in range(ln)]


for i in target:
    stat[ord(i) - a_ord] += 1

idx = 0
is_failed = False
is_odd_used = False
for i in range(26):
    if stat[i] % 2 == 1:
        if ln % 2 == 1 and not is_odd_used:
            stat[i] -= 1
            is_odd_used = True
            result[ln // 2] = chr(a_ord + i)
        else:
            is_failed = True
            break
    while stat[i] > 0 and idx < ln:
        stat[i] -= 2
        result[idx] = result[ln - 1 - idx] = chr(a_ord + i)
        idx += 1

if is_failed:
    sys.stdout.write('I\'m Sorry Hansoo\n')
else:
    sys.stdout.write(f"{''.join(result)}\n")
