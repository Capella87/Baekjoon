// 백준 2525번 문제 : 오븐 시계
// https://www.acmicpc.net/problem/2525
// 알고리즘 분류 : 수학, 사칙연산

package main

import (
	"fmt"
)

func main() {
	var a int
	var b int
	var c int

	fmt.Scan(&a, &b)
	fmt.Scan(&c)

	var now int = (a*60 + b + c) % 1440
	var hour int = now / 60
	var minute int = now % 60

	fmt.Println(hour, minute)
}
