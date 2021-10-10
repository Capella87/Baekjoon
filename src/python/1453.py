
# 백준 1453번 문제 : 피시방 알바
# https://www.acmicpc.net/problem/1453
# 알고리즘 분류 : 구현

n = int(input())
declined = 0
q = list(map(int, input().strip().split()))[:n]
pcBang = [False] * 100
for i in range(0, n):
    if pcBang[q[i] - 1]:
        declined += 1
    else:
        pcBang[q[i] - 1] = True
print(declined)