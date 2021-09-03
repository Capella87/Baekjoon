# 백준 2748번 문제 : 피보나치 수 2
# https://www.acmicpc.net/problem/2748
# 알고리즘 분류 : 수학, 다이나믹 프로그래밍

n = int(input())
result = f1 = 0
f2 = 1

for i in range(1, n):
    result = (f1 + f2)
    f1 = f2
    f2 = result
if n == 1:
    print(f2)
else:
    print(result)