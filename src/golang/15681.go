// 백준 15681번 문제 : 트리와 쿼리
// https://www.acmicpc.net/problem/15681
// 알고리즘 분류 : 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색, 트리에서의 다이나믹 프로그래밍

package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var n, r, q, target int
var connections [][]int
var nodeCount []int
var parents []int

func main() {
	defer writer.Flush()

	fmt.Fscan(reader, &n, &r, &q)
	nodeCount = make([]int, n+1)
	parents = make([]int, n+1)
	connections = make([][]int, n+1)

	for i := 1; i < n; i++ {
		var u, v int
		fmt.Fscan(reader, &u, &v)
		connections[u] = append(connections[u], v)
		connections[v] = append(connections[v], u)
	}
	makeTree(r, -1)
	for i := 0; i < q; i++ {
		fmt.Fscan(reader, &target)
		fmt.Fprintln(writer, getSubNodeCount(target))
	}
}

func makeTree(node int, parent int) int {
	parents[node] = parent
	nodeCount[node] = 1

	var l = len(connections[node])
	for i := 0; i < l; i++ {
		if connections[node][i] == parent {
			continue
		}
		nodeCount[node] += makeTree(connections[node][i], node)
	}
	return nodeCount[node]
}

func getSubNodeCount(node int) int {
	return nodeCount[node]
}
