// 백준 2294번 문제 : 동전 2
// https://www.acmicpc.net/problem/2294
// 알고리즘 분류 : 다이나믹 프로그래밍

// Top-down memoization approach

package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var n, k int
var cache []int
var coins []int

func main() {
	defer writer.Flush()
	fmt.Fscan(reader, &n, &k)
	coins = make([]int, n)
	cache = make([]int, k+1)

	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &coins[i])
	}
	fmt.Fprintln(writer, getMinimumCoins(k))
}

func getMinimumCoins(p int) int {
	if cache[p] != 0 || p == 0 {
		return cache[p]
	}

	cache[p] = -1
	for i := 0; i < n; i++ {
		if p < coins[i] {
			continue
		}
		var coinCount = getMinimumCoins(p - coins[i])
		if coinCount == -1 {
			continue
		}
		coinCount++
		if cache[p] == -1 || coinCount < cache[p] {
			cache[p] = coinCount
		}
	}
	return cache[p]
}
