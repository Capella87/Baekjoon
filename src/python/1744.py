# 백준 1744번 문제 : 수 묶기
# https://www.acmicpc.net/problem/1744
# 알고리즘 분류 : 그리디 알고리즘, 정렬, 많은 조건 분기

import sys

n = int(sys.stdin.readline().strip())
arr = [int(sys.stdin.readline().strip()) for _ in range(n)]

arr_d = sorted(arr, key=lambda x: -x)
l = len(arr_d)

sum = 0
c_reg = arr_d[0]
is_binded = False
# 양수와 0 및 음수, 두 부분으로 나누어서 처리해야 한다.
# 양수
if c_reg > 0:
    i = 1
    while i < l and arr_d[i] > 0:
        if is_binded:
            is_binded = False
            c_reg = arr_d[i]
        elif (c_reg * arr_d[i]) >= (c_reg + arr_d[i]):
            is_binded = True
            c_reg *= arr_d[i]
            sum += c_reg
        else:
            sum += c_reg
            c_reg = arr_d[i]
        i += 1
    if not is_binded:
        sum += c_reg

i = l - 2
c_reg = arr_d[l - 1]
is_binded = False
# 음수
if c_reg <= 0:
    while i >= 0 and arr_d[i] <= 0:
        if is_binded:
            is_binded = False
            c_reg = arr_d[i]
        elif (c_reg * arr_d[i]) >= (c_reg + arr_d[i]):
            is_binded = True
            c_reg *= arr_d[i]
            sum += c_reg
        else:
            sum += c_reg
            c_reg = arr_d[i]
        i -= 1
    if not is_binded:
        sum += c_reg
sys.stdout.write(f'{sum}\n')
