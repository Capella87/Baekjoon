# 백준 2448번 문제 : 별 찍기 - 11
# https://www.acmicpc.net/problem/2448
# 알고리즘 분류 : 재귀

import sys


def draw(arr: list[list[str]], row, blanks: int) -> None:
    arr[row][blanks + 1] = '*'
    arr[row + 1][blanks] = arr[row + 1][blanks + 2] = '*'
    for i in range(5):
        arr[row + 2][blanks - 1 + i] = '*'

def startriangle(arr: list[list[str]], n: int, row: int, blanks: int) -> None:
    if n == 3:
        draw(arr, row, blanks)
        return
    startriangle(arr, n // 2, row, blanks)
    startriangle(arr, n // 2, row + (n // 2), blanks - (n // 2))
    startriangle(arr, n // 2, row + (n // 2), blanks - (n // 2) + n)


def print_result(arr: list[list[str]], n: int) -> None:
    for row in arr:
        sys.stdout.write(''.join(row) + '\n')


n = int(sys.stdin.readline())
arr = [[' ' for _ in range(n * 2)] for _ in range(n)]
startriangle(arr, n, 0, n - 2)
print_result(arr, n)
