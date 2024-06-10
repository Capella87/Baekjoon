// 백준 12018번 문제 : Yonsei TOTO
// https://www.acmicpc.net/problem/12018
// 알고리즘 분류 : 그리디 알고리즘, 정렬

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func main() {
	defer writer.Flush()

	var n, m int
	fmt.Fscan(reader, &n, &m)

	var mileages = make([]int, n)

	for i := 0; i < n; i++ {
		var applicants, capacity int

		fmt.Fscan(reader, &applicants, &capacity)
		people := make([]int, applicants)

		for j := 0; j < applicants; j++ {
			fmt.Fscan(reader, &people[j])
		}
		if applicants < capacity {
			mileages[i] = 1
			continue
		}
		sort.Sort(sort.Reverse(sort.IntSlice(people)))
		mileages[i] = people[capacity-1]
	}

	var total, i int = 0, 0
	sort.Ints(mileages)

	for i < n {
		if total+mileages[i] > m {
			break
		}
		total += mileages[i]
		i++
	}
	fmt.Fprintln(writer, i)
}
