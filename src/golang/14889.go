// 백준 14889번 문제 : 스타트와 링크
// https://www.acmicpc.net/problem/14889
// 알고리즘 분류 : 브루트포스 알고리즘, 백트래킹

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var n, halfN int
var startTeam []int
var linkTeam []int
var result int = math.MaxInt32

func main() {
	defer writer.Flush()
	fmt.Fscan(reader, &n)

	halfN = n / 2
	var stats = make([][]int, n+1)

	for i := 1; i <= n; i++ {
		stats[i] = make([]int, n+1)
		for j := 1; j <= n; j++ {
			fmt.Fscan(reader, &stats[i][j])
		}
	}
	matchTeam(stats, 1)
	fmt.Fprintln(writer, result)
}

func matchTeam(stats [][]int, number int) {
	if number > n {
		if len(startTeam) == halfN && len(linkTeam) == halfN {
			startSum := 0
			linkSum := 0

			for i := 0; i < halfN; i++ {
				for j := i + 1; j < halfN; j++ {
					startSum += stats[startTeam[i]][startTeam[j]] + stats[startTeam[j]][startTeam[i]]
					linkSum += stats[linkTeam[i]][linkTeam[j]] + stats[linkTeam[j]][linkTeam[i]]
				}
			}
			var diff = startSum - linkSum
			if diff < 0 {
				diff *= -1
			}
			if diff < result {
				result = diff
			}
		}
		return
	}
	startTeam = append(startTeam, number)
	matchTeam(stats, number+1)
	startTeam = startTeam[:len(startTeam)-1]

	linkTeam = append(linkTeam, number)
	matchTeam(stats, number+1)
	linkTeam = linkTeam[:len(linkTeam)-1]
}
