// 백준 2480번 문제 : 주사위 세개
// https://www.acmicpc.net/problem/2480
// 알고리즘 분류 : 수학, 구현, 사칙연산, 많은 조건 분기

package main

import "fmt"

func main() {
	var a, b, c int
	var result int = 0

	fmt.Scan(&a, &b, &c)

	if a == b && a == c && b == c {
		result = 10000 + 1000*a
	} else if a == b || a == c {
		result = 1000 + a*100
	} else if b == c {
		result = 1000 + b*100
	} else {
		result = max(a, b, c) * 100
	}

	fmt.Println(result)
}
