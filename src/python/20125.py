# 백준 20125번 문제 : 쿠키의 신체 측정
# https://www.acmicpc.net/problem/20125
# 알고리즘 분류 : 구현

import sys

def get_head(arr: list, n: int) -> (int, int):
    for i in range(n):
        for j in range(n):
            if picture[i][j] == '*':
                return i, j
    return 0, 0

n = int(sys.stdin.readline())
picture = [list(sys.stdin.readline()) for _ in range(n)]
head_i, head_j = get_head(picture, n)

heart_i = head_i + 1
heart_j = head_j
left_arm_len = right_arm_len = hip_len = left_leg_len = right_leg_len = 0

for j in range(heart_j):
    if picture[heart_i][j] == '_':
        continue
    left_arm_len += 1
for j in range(heart_j + 1, n):
    if picture[heart_i][j] == '_':
        break
    right_arm_len += 1

for i in range(heart_i + 1, n):
    if picture[i][heart_j] == '_':
        break
    hip_len += 1

# Get left and right
for i in range(heart_i + hip_len + 1, n):
    if picture[i][heart_j - 1] == '*':
        left_leg_len += 1
    if picture[i][heart_j + 1] == '*':
        right_leg_len += 1

sys.stdout.write(f'{heart_i + 1} {heart_j + 1}\n')
sys.stdout.write(f'{left_arm_len} {right_arm_len} {hip_len} {left_leg_len} {right_leg_len}\n')
