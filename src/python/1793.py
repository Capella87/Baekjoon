# 백준 15988번 문제 : 타일링
# https://www.acmicpc.net/problem/1793
# 알고리즘 분류 : 다이나믹 프로그래밍

# Bottom-up method

from sys import stdin

cache = [0] * 251
cache[0] = 1
cache[1] = 1
for i in range(2, 251):
    cache[i] = cache[i - 1] + 2 * cache[i - 2]

for n in stdin: # Receive input until EOF
    print(cache[int(n)])
