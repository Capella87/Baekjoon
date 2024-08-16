// 백준 5567번 문제 : 결혼식
// https://www.acmicpc.net/problem/5567
// 알고리즘 분류 : 그래프 이론, 그래프 탐색

package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var n, m int
var mutualFriends []int
var isVisited []bool
var result int = 0

func main() {
	defer writer.Flush()

	fmt.Fscan(reader, &n)
	fmt.Fscan(reader, &m)
	var network = make(map[int][]int)
	isVisited = make([]bool, n+1)
	for i := 1; i <= n; i++ {
		network[i] = make([]int, 0)
	}
	for i := 0; i < m; i++ {
		var src, dest int
		fmt.Fscan(reader, &src, &dest)
		network[src] = append(network[src], dest)
		network[dest] = append(network[dest], src)
		if src == 1 {
			mutualFriends = append(mutualFriends, dest)
		}
	}
	isVisited[1] = true
	var l = len(mutualFriends)
	for i := 0; i < l; i++ {
		if !isVisited[mutualFriends[i]] {
			result += 1
			isVisited[mutualFriends[i]] = true
		}
		var l2 = len(network[mutualFriends[i]])
		for j := 0; j < l2; j++ {
			if !isVisited[network[mutualFriends[i]][j]] {
				result += 1
				isVisited[network[mutualFriends[i]][j]] = true
			}
		}
	}
	fmt.Fprintln(writer, result)
}
