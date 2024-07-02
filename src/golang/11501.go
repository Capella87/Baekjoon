// 백준 11501번 문제 : 주식
// https://www.acmicpc.net/problem/11501
// 알고리즘 분류 : 그리디 알고리즘

package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var t int
var arr [1_000_000]int

func main() {
	defer writer.Flush()

	fmt.Fscan(reader, &t)
	for i := 0; i < t; i++ {
		var days int
		var result int64 = 0
		fmt.Fscan(reader, &days)

		for j := 0; j < days; j++ {
			fmt.Fscan(reader, &arr[j])
		}
		var mx int = arr[days-1]
		for j := days - 2; j >= 0; j-- {
			if mx < arr[j] {
				mx = arr[j]
			} else {
				result += int64(mx - arr[j])
			}
		}
		fmt.Fprintln(writer, result)
	}
}
