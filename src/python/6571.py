# 백준 6571번 문제 : 피보나치 수의 개수
# https://www.acmicpc.net/problem/6571
# 알고리즘 분류 : 수학, 다이나믹 프로그래밍, 브루트포스 알고리즘, 임의 정밀도 / 큰 수 연산

saved = [0] * 1001
saved[0] = 1
saved[1] = 2
for i in range(2, 1001):
    saved[i] = saved[i - 2] + saved[i - 1]

while True:
    a, b = map(int, input().split())
    if a == b == 0: break
    
    pos = 0
    count = 0
    while saved[pos] < a:
        pos += 1
    while saved[pos] <= b:
        count += 1
        pos += 1
    print(count)
