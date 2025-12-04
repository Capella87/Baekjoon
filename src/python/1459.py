# 백준 1459번 문제 : 걷기
# https://www.acmicpc.net/problem/1459
# 알고리즘 분류 : 수학, 많은 조건 분기

import sys

x, y, w, s = map(int, sys.stdin.readline().strip().split())

mx_diagonal = min(x, y)
mn_w = x - mx_diagonal + y - mx_diagonal
rt = 0
if (2 * w) > s:
    rt = mx_diagonal * s
    if s < w:
        rt += (mn_w // 2) * 2 * s + (mn_w % 2) * w
    else:
        rt += mn_w * w
else:
    rt = (x + y) * w
sys.stdout.write(f'{rt}\n')
