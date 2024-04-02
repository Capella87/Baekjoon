// 백준 4134번 문제 : 다음 소수
// https://www.acmicpc.net/problem/4134
// 알고리즘 분류 : 수학, 브루트포스 알고리즘, 정수론, 소수 판정

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	var reader *bufio.Reader = bufio.NewReader(os.Stdin)
	var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

	defer writer.Flush()

	var n int
	var target int64
	fmt.Fscan(reader, &n)

	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &target)

		if target <= 2 {
			target = 2
			goto res
		}

		if target%2 == 0 {
			target++
		}

		for !isprime(target) {
			target += 2
		}
	res:
		fmt.Fprintf(writer, "%d\n", target)
	}
}

func isprime(target int64) bool {
	if target < 2 {
		return false
	}

	var sqrtbound int64 = int64(math.Sqrt(float64(target)))
	for i := int64(2); i <= sqrtbound; i++ {
		if target%i == 0 {
			return false
		}
	}

	return true
}
