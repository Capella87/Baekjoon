// 백준 27172번 문제 : 수 나누기 게임
// https://www.acmicpc.net/problem/27172
// 알고리즘 분류 : 수학, 브루트포스 알고리즘, 정수론, 소수 판정, 에라스토테네스의 체

package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var n int
var numbers [1000001]int
var results [1000001]int
var arr []int
var end = 0

func main() {
	defer writer.Flush()
	fmt.Fscan(reader, &n)
	arr = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &arr[i])
		numbers[arr[i]] = 1
		if end < arr[i] {
			end = arr[i]
		}
	}
	for i := 0; i < n; i++ {
		for j := arr[i] * 2; j <= end; j += arr[i] {
			if numbers[j] == 0 {
				continue
			}
			results[arr[i]]++
			results[j] -= 1
		}
	}
	for i := 0; i < n; i++ {
		fmt.Fprintf(writer, "%d ", results[arr[i]])
	}
	fmt.Fprint(writer, "\n")
}
