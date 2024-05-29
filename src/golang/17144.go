// 백준 17144번 문제 : 미세먼지 안녕!
// https://www.acmicpc.net/problem/17144
// 알고리즘 분류 : 구현, 시뮬레이션

package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

// acR and acC point to the lower part of the air conditioner
var r, c, t, acR int
var rMove = []int{0, 1, 0, -1}
var cMove = []int{1, 0, -1, 0}

func main() {
	defer writer.Flush()

	fmt.Fscan(reader, &r, &c, &t)
	var room = make([][]int, r)
	var diffusionDiff = make([][]int, r)

	for i := 0; i < r; i++ {
		room[i] = make([]int, c)
		diffusionDiff[i] = make([]int, c)
		for j := 0; j < c; j++ {
			fmt.Fscan(reader, &room[i][j])
			if room[i][j] == -1 {
				acR = i
			}
		}
	}

	fmt.Fprintln(writer, SimulateAirQualityAtRoom(room, diffusionDiff))
}

func SimulateAirQualityAtRoom(room [][]int, diffusionCache [][]int) int {
	var curTime int = 0
	var newR, newC int

	for curTime < t {
		// Diffusion
		for i := 0; i < r; i++ {
			for j := 0; j < c; j++ {
				if room[i][j] == -1 {
					continue
				}
				var diffusedDust int = room[i][j] / 5

				for k := 0; k < 4; k++ {
					newR = i + rMove[k]
					newC = j + cMove[k]

					if newR < 0 || newC < 0 || newR >= r || newC >= c || room[newR][newC] == -1 {
						continue
					}

					diffusionCache[newR][newC] += diffusedDust
					room[i][j] -= diffusedDust
				}
			}
		}

		for i := 0; i < r; i++ {
			for j := 0; j < c; j++ {
				room[i][j] += diffusionCache[i][j]
				diffusionCache[i][j] = 0
			}
		}

		// Operate the air conditioner
		// Inhale dust from neighbor blocks
		upperAcR := acR - 1
		room[upperAcR-1][0] = 0
		room[acR+1][0] = 0

		for i := upperAcR - 1; i > 0; i-- {
			room[i][0] = room[i-1][0]
		}
		for i := acR + 1; i < r-1; i++ {
			room[i][0] = room[i+1][0]
		}

		for i := 0; i < c-1; i++ {
			room[0][i] = room[0][i+1]
			room[r-1][i] = room[r-1][i+1]
		}

		for i := 0; i < upperAcR; i++ {
			room[i][c-1] = room[i+1][c-1]
		}
		for i := r - 1; i > acR; i-- {
			room[i][c-1] = room[i-1][c-1]
		}

		for i := c - 1; i > 1; i-- {
			room[upperAcR][i] = room[upperAcR][i-1]
			room[acR][i] = room[acR][i-1]
		}
		room[upperAcR][1] = 0
		room[acR][1] = 0

		curTime++
	}

	return GetMicrodustSum(room)
}

func GetMicrodustSum(room [][]int) int {
	var sum int = 0

	for i := 0; i < r; i++ {
		for j := 0; j < c; j++ {
			if room[i][j] != -1 {
				sum += room[i][j]
			}
		}
	}
	return sum
}
