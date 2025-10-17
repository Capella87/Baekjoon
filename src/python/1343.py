# 백준 1343번 문제 : 폴리오미노
# https://www.acmicpc.net/problem/1343
# 알고리즘 분류 : 구현, 그리디 알고리즘, 문자열

import sys

board = sys.stdin.readline().strip()
polyomino = []
le = len(board)

is_invalid = False
cont_vacant = 0
for i in range(le + 1):
    if i == le or board[i] == '.':
        for j in range(cont_vacant // 4):
            polyomino.append('AAAA')
        cont_vacant %= 4
        if cont_vacant == 2:
            polyomino.append('BB')
            cont_vacant %= 2
        if 0 < cont_vacant % 2 < 2:
            is_invalid = True
            break
        if i < le:
            polyomino.append('.')
    else:
        cont_vacant += 1
if not is_invalid:
    sys.stdout.write(''.join(polyomino) + '\n')
else:
    sys.stdout.write('-1\n')
