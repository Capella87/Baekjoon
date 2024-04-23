// 백준 1965번 문제 : 상자넣기
// https://www.acmicpc.net/problem/1965
// 알고리즘 분류 : 다이나믹 프로그래밍

package main

import (
	"bufio"
	"fmt"
	"os"
)

var n int
var result int = -1

func main() {
	var reader *bufio.Reader = bufio.NewReader(os.Stdin)
	var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscanln(reader, &n)
	boxSizes := make([]int, n)
	cache := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &boxSizes[i])
		for j := 0; j < i; j++ {
			if boxSizes[j] < boxSizes[i] {
				cache[i] = max(cache[i], cache[j])
			}
		}
		cache[i] += 1
		result = max(result, cache[i])
	}

	fmt.Fprintln(writer, result)
}
