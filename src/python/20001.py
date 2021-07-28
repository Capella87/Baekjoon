# 백준 20001번 문제 : 고무오리 디버깅
# https://www.acmicpc.net/problem/20001
# 알고리즘 분류 : 구현, 자료 구조, 스택

from collections import deque

duck = deque()

temp = input()
while temp != '고무오리 디버깅 끝':
    if (temp == '문제'):
        duck.append('1')
    elif temp == '고무오리' and len(duck) == 0:
        duck.append('1')
        duck.append('1')
    elif temp == '고무오리' and len(duck) > 0:
        duck.pop()
    temp = input()

if len(duck) == 0:
    print('고무오리야 사랑해')
else:
    print('힝구')