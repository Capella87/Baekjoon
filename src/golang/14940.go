// 백준 14940번 문제 : 쉬운 최단거리
// https://www.acmicpc.net/problem/14940
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

package main

import (
	"bufio"
	"fmt"
	"os"
)

type Location struct {
	X int
	Y int
}

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

var XMove = [4]int{1, 0, -1, 0}
var YMove = [4]int{0, 1, 0, -1}
var n, m int

func main() {
	defer writer.Flush()

	var targetY, targetX int

	fmt.Fscanln(reader, &n, &m)

	boardMap := make([][]int, n)
	distanceInfo := make([][]int, n)
	for i := 0; i < n; i++ {
		boardMap[i] = make([]int, m)
		distanceInfo[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Fscan(reader, &boardMap[i][j])
			if boardMap[i][j] == 2 {
				targetY = i
				targetX = j
				distanceInfo[i][j] = 0
			} else if boardMap[i][j] == 0 {
				distanceInfo[i][j] = 0
			} else {
				distanceInfo[i][j] = -1
			}
		}
		reader.ReadString('\n')
	}

	bfs(&boardMap, &distanceInfo, targetY, targetX)
	printMapMoves(&distanceInfo)
}

func bfs(boardMap *[][]int, distanceInfo *[][]int, targetY int, targetX int) {
	var x, y int
	var moves int
	var queue []Location
	queue = append(queue, Location{targetX, targetY})

	for len(queue) > 0 {
		queue, x, y = dequeue(queue)
		moves = (*distanceInfo)[y][x]
		for i := 0; i < 4; i++ {
			newX := x + XMove[i]
			newY := y + YMove[i]

			if newX < 0 || newY < 0 || newX >= m || newY >= n {
				continue
			}

			if (*boardMap)[newY][newX] == 1 &&
				(*distanceInfo)[newY][newX] == -1 {
				queue = enqueue(queue, newX, newY)
				(*distanceInfo)[newY][newX] = moves + 1
			}
		}
	}
}

func enqueue(queue []Location, x int, y int) []Location {
	queue = append(queue, Location{x, y})
	return queue
}

func dequeue(queue []Location) ([]Location, int, int) {
	target := queue[0]
	if len(queue) == 1 {
		var temp = []Location{}
		return temp, target.X, target.Y
	}

	return queue[1:], target.X, target.Y
}

func printMapMoves(moveMap *[][]int) {
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Fprintf(writer, "%d ", (*moveMap)[i][j])
		}
		fmt.Fprint(writer, "\n")
	}
}
