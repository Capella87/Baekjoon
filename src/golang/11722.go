// 백준 11722번 문제 : 가장 긴 감소하는 부분 수열
// https://www.acmicpc.net/problem/11722
// 알고리즘 분류 : 다이나믹 프로그래밍

package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var n int
var lds []int
var lastLds = 0

func main() {
	defer writer.Flush()

	fmt.Fscan(reader, &n)
	var arr = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &arr[i])
	}
	lds = append(lds, arr[0])

	for i := 1; i < n; i++ {
		if lds[lastLds] > arr[i] {
			lds = append(lds, arr[i])
			lastLds++
		} else {
			lds[lowerBound(0, lastLds, arr[i])] = arr[i]
		}
	}
	fmt.Fprintln(writer, lastLds+1)
}

func lowerBound(start int, end int, target int) int {
	for start < end {
		var mid int = (start + end) / 2
		if lds[mid] > target {
			start = mid + 1
		} else {
			end = mid
		}
	}
	// Locating right side as possible for longer array length
	return end
}
