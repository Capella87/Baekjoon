# 백준 1789번 문제 : 수들의 합
# https://www.acmicpc.net/problem/1789
# 알고리즘 분류 : 수학, 그리디 알고리즘

n = int(input())

total = 0
i = 0
while total <= n:
    i += 1
    total += i
i -= 1
print(i)
