// 백준 2468번 문제 : 안전 영역
// https://www.acmicpc.net/problem/2468
// 알고리즘 분류 : 그래프 이론, 브루트포스 알고리즘, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Graph
{
    private int[][] arr;
    private int n;
    private boolean[][] isVisited;
    private int max = 1;
    private int min = 100;
    private int rt = 0;
    private int[] yMove = new int[] { -1, 0, 1, 0 };
    private int[] xMove = new int[] { 0, 1, 0, -1 };

    public Graph() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr = new int[n][];
        isVisited = new boolean[n][];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
            isVisited[i] = new boolean[n];

            String[] st = br.readLine().split(" ");
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = Integer.parseInt(st[j]);
                if (max < arr[i][j]) max = arr[i][j];
                if (min > arr[i][j]) min = arr[i][j];
            }
        }
    }

    private void dfs(int y, int x, int level)
    {
        isVisited[y][x] = true;
        for (int i = 0; i < 4; i++)
        {
            int n_y = y + yMove[i];
            int n_x = x + xMove[i];

            if (n_y >= 0 && n_y < n && n_x >= 0 && n_x < n)
                if (!isVisited[n_y][n_x] && arr[n_y][n_x] > level)
                    dfs(n_y, n_x, level);
        }
    }

    private void resetVisited()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                isVisited[i][j] = false;
    }

    public void checkSafeRegion()
    {
        for (int i = min - 1; i <= max; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (!isVisited[j][k] && i < arr[j][k])
                    {
                        dfs(j, k, i);
                        count++;
                    }
                }
            }
            if (count > rt) rt = count;
            resetVisited();
        }
    }

    public int getResult()
    {
        return rt;
    }
}

public class Main
{
    public static void main(String[] args) throws IOException
    {
        var gr = new Graph();
        gr.checkSafeRegion();
        System.out.println(gr.getResult());
    }
}