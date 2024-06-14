// 백준 10830번 문제 : 행렬 제곱
// https://www.acmicpc.net/problem/10830
// 알고리즘 분류 : 수학, 분할 정복, 분할 정복을 이용한 거듭제곱, 선형대수학

package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var n int
var b int64

func main() {
	defer writer.Flush()

	fmt.Fscan(reader, &n, &b)

	var baseArray = make([][]int, n)
	for i := 0; i < n; i++ {
		baseArray[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Fscan(reader, &baseArray[i][j])
		}
	}

	var result = matrixPower(baseArray, b)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Fprintf(writer, "%d ", result[i][j]%1000)
		}
		fmt.Fprint(writer, "\n")
	}
}

func matrixPower(baseArray [][]int, exponent int64) [][]int {
	if exponent == 1 {
		return copyMatrix(baseArray)
	}

	var mid = matrixPower(baseArray, exponent/2)
	var rt = multMatrix(mid, mid)
	if exponent%2 == 1 {
		return multMatrix(rt, baseArray)
	}
	return rt
}

func multMatrix(a [][]int, b [][]int) [][]int {
	var rt = createMatrix()

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				rt[i][j] += (a[i][k] * b[k][j]) % 1000
			}
			rt[i][j] %= 1000
		}
	}
	return rt
}

func createMatrix() [][]int {
	var rt = make([][]int, n)
	for i := 0; i < n; i++ {
		rt[i] = make([]int, n)
	}
	return rt
}

func copyMatrix(orig [][]int) [][]int {
	var rt = make([][]int, n)
	for i := 0; i < n; i++ {
		rt[i] = make([]int, n)
		for j := 0; j < n; j++ {
			rt[i][j] = orig[i][j]
		}
	}
	return rt
}
