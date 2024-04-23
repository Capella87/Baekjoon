// 백준 9663번 문제 : N-Queen
// https://www.acmicpc.net/problem/9663
// 알고리즘 분류 : 브루트포스 알고리즘, 백트래킹

package main

import (
	"bufio"
	"fmt"
	"os"
)

var n int
var result int = 0
var diagonalSize int

func main() {
	var reader *bufio.Reader = bufio.NewReader(os.Stdin)
	var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &n)

	diagonalSize = n*2 - 1
	colStatus := make([]bool, n)
	diagonalStatus := make([]bool, diagonalSize)
	skewDiagonalStatus := make([]bool, diagonalSize)

	nQueen(0, &colStatus, &diagonalStatus, &skewDiagonalStatus)

	fmt.Fprintln(writer, result)
}

func nQueen(row int, colStatus *[]bool,
	diagonalStatus *[]bool, skewDiagonalStatus *[]bool) {
	if row == n {
		return
	}

	for i := 0; i < n; i++ {
		if (*colStatus)[i] || (*diagonalStatus)[n-1+row-i] || (*skewDiagonalStatus)[row+i] {
			continue
		}

		(*colStatus)[i] = true
		(*diagonalStatus)[n-1+row-i] = true
		(*skewDiagonalStatus)[row+i] = true

		if row == n-1 {
			result += 1
		} else {
			nQueen(row+1, colStatus, diagonalStatus, skewDiagonalStatus)
		}

		(*skewDiagonalStatus)[row+i] = false
		(*diagonalStatus)[n-1+row-i] = false
		(*colStatus)[i] = false
	}
}
