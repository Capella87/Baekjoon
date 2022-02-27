# 백준 2407번 문제 : 조합
# https://www.acmicpc.net/problem/2407
# 알고리즘 분류 : 수학, 다이나믹 프로그래밍, 조합론, 임의 정밀도 / 큰 수 연산

n, m = map(int, input().split(' '))

if (n - m) < m:
    m = n - m

cache = [0] * (n + 1)
cache[0] = 1

for i in range(1, n + 1):
    for j in range (m, -1, -1):
        cache[j] = cache[j] + cache[j - 1]

print(cache[m])
