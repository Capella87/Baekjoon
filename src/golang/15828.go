// 백준 15828번 문제 : Router
// https://www.acmicpc.net/problem/15828
// 알고리즘 분류 : 자료 구조, 큐

package main

import (
	"bufio"
	"fmt"
	"os"
)

func enqueue(queue []int, target int) []int {
	queue = append(queue, target)

	return queue
}

func dequeue(queue []int) []int {
	if len(queue) == 0 {
		return queue
	}

	return queue[1:]
}

func top(queue []int) int {
	if len(queue) == 0 {
		return -1
	}

	return queue[0]
}

func main() {
	var reader *bufio.Reader = bufio.NewReader(os.Stdin)
	var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

	defer writer.Flush()

	var n, packet int
	var count int = 0

	fmt.Fscan(reader, &n)

	router := make([]int, 0)

	for {
		fmt.Fscan(reader, &packet)

		if packet == -1 {
			break
		} else if packet == 0 {
			router = dequeue(router)
			count--
			continue
		}

		if count < n {
			router = enqueue(router, packet)
			count++
		}
	}

	if count == 0 {
		fmt.Fprintln(writer, "empty")
	} else {
		for i := 0; i < count; i++ {
			fmt.Fprintf(writer, "%d ", router[i])
		}
		fmt.Fprintf(writer, "\n")
	}
}
