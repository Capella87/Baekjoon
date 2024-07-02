// 백준 2580번 문제 : 스도쿠
// https://www.acmicpc.net/problem/2580
// 알고리즘 분류 : 백트래킹

package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var sudokuBoard [9][9]int

func main() {
	defer writer.Flush()

	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			fmt.Fscan(reader, &sudokuBoard[i][j])
		}
	}
	sudokuSolve(0, 0)
	sudokuPrint(sudokuBoard)
}

func sudokuSolve(row int, col int) bool {
	if col == 9 {
		row++
		col = 0
	}
	if row == 9 {
		return true
	}
	if sudokuBoard[row][col] != 0 {
		return sudokuSolve(row, col+1)
	}

	for i := 1; i <= 9; i++ {
		if isNumberValid(row, col, i) {
			sudokuBoard[row][col] = i
			if sudokuSolve(row, col+1) {
				return true
			}
			sudokuBoard[row][col] = 0
		}
	}
	return false
}

func isNumberValid(row int, col int, num int) bool {
	var blockBaseRow int = (row / 3) * 3
	var blockBaseCol int = (col / 3) * 3
	for i := 0; i < 9; i++ {
		if sudokuBoard[row][i] == num {
			return false
		}
		if sudokuBoard[i][col] == num {
			return false
		}
		if sudokuBoard[blockBaseRow+i/3][blockBaseCol+i%3] == num {
			return false
		}
	}
	return true
}

func sudokuPrint(board [9][9]int) {
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			fmt.Fprintf(writer, "%d ", board[i][j])
		}
		fmt.Fprintf(writer, "\n")
	}
}
