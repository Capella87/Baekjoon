# 백준 11123번 문제 : 양 한마리... 양 두마리...
# https://www.acmicpc.net/problem/11123
# 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

from collections import deque

y_move = [-1, 0, 1, 0]
x_move = [0, 1, 0, -1]


def dfs(y, x, is_visited, ranch):
    stk = deque()

    stk.appendleft((y, x))
    while len(stk) > 0:
        (y, x) = stk.popleft()
        if is_visited[y][x] is True:
            continue
        is_visited[y][x] = True
        for i in range(4):
            global y_move
            global x_move
            idx_y = y + y_move[i]
            idx_x = x + x_move[i]
            if (0 <= idx_y < len(ranch)) and (0 <= idx_x < len(ranch[0])):  # Python can compress comparator expression
                if is_visited[idx_y][idx_x] is False and ranch[idx_y][idx_x] == '#':
                    stk.appendleft((idx_y, idx_x))


t = int(input())
for c in range(t):
    h, w = map(int, input().split(' '))
    ranch = []
    for i in range(h):
        ranch.append(list(input()))  # 2D chr list input
    is_visited = [[False] * w for _ in range(h)]

    sheep_count = 0
    for i in range(h):
        for j in range(w):
            if is_visited[i][j] == False and ranch[i][j] == '#':
                dfs(i, j, is_visited, ranch)
                sheep_count += 1
    print(sheep_count)
