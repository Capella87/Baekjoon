# 백준 2738번 문제 : 행렬 덧셈
# https://www.acmicpc.net/problem/2738
# 알고리즘 분류 : 수학, 구현, 사칙연산

n, m = map(int, input().split(' '))

# Insert elements from user input to array
a = []
for i in range(n):
    a.append([int(x) for x in input().split(' ')])
b = []
for i in range(n):
    b.append([int(x) for x in input().split(' ')])

c = b
for i in range(n):
    for j in range(m):
        c[i][j] = a[i][j] + b[i][j]
        print(c[i][j], end=' ')
    print()
