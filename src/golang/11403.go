// 백준 11403번 문제 : 경로 찾기
// https://www.acmicpc.net/problem/11403
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 최단 경로, 플로이드-워셜

package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

var n int

func main() {
	defer writer.Flush()

	fmt.Fscan(reader, &n)

	var network = make([][]int32, n+1)

	for i := 1; i <= n; i++ {
		network[i] = make([]int32, n+1)
		for j := 1; j <= n; j++ {
			fmt.Fscan(reader, &network[i][j])
		}
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if i == j {
				continue
			}
			for k := 1; k <= n; k++ {
				if k == i {
					continue
				}
				if network[j][i] == 1 && network[i][k] == 1 && network[j][k] == 0 {
					network[j][k] = 1
				}
			}
		}
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			fmt.Fprintf(writer, "%d ", network[i][j])
		}
		fmt.Fprint(writer, "\n")
	}
}
