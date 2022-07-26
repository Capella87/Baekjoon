# 백준 1759번 문제 : 암호 만들기
# https://www.acmicpc.net/problem/1759
# 알고리즘 분류 : 수학, 브루트포스 알고리즘, 조합론, 백트래킹

import sys

l, c = map(int, sys.stdin.readline().split(' '))
chars = list(map(str, sys.stdin.readline().strip('\n').split(' ')))
chars.sort()
result = ['0' for i in range(l)]

vows = "aiueo"

def password(count, vowel, consonant, pos):
    global l, c

    if count == l:
        if vowel >= 1 and consonant >= 2:
            print(''.join(map(str, result)))
        return
    elif pos == c:
        return
    for i in range(pos, c):
        result[count] = chars[i]
        if vows.find(chars[i]) == -1:
            password(count + 1, vowel, consonant + 1, i + 1)
        else:
            password(count + 1, vowel + 1, consonant, i + 1)

password(0, 0, 0, 0)
