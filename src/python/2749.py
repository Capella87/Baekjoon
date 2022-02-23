# 백준 2749번 문제 : 피보나치 수 3
# https://www.acmicpc.net/problem/16940
# 알고리즘 분류 : 수학, 분할 정복을 이용한 거듭제곱

'''
Pisano period

M = 10^k
period = 15 * (10^(k - 1)) (k > 2)
fibonacci(n % period) % M is equal to fibonacci(n) % M
'''

n = int(input())
pisano = n % (15 * 100000)

f0 = 0
f1 = 1
f2 = 1

for i in range(2, pisano + 1):
    f2 = (f1 + f0) % 1000000
    f0 = f1
    f1 = f2

print(f2 % 1000000)