// 백준 31589번 문제 : 포도주 시음
// https://www.acmicpc.net/problem/31589
// 알고리즘 분류 : 그리디 알고리즘, 정렬, 두 포인터

package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

var n, k, front, rear, i int

func main() {
	defer writer.Flush()

	fmt.Fscan(reader, &n, &k)
	var wines = make([]int64, n)
	var sum, prev int64 = 0, 0

	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &wines[i])
	}
	// ASC
	slices.Sort(wines)
	i, front, rear = 0, 0, n-1
	prev = 0

	for i < k {
		// Rear
		sum += wines[rear] - prev
		rear--
		i++

		if i == k {
			break
		}

		// Front
		prev = wines[front]
		front++
		i++
	}

	fmt.Fprintln(writer, sum)
}
