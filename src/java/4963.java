// 백준 4963번 문제 : 섬의 개수
// https://www.acmicpc.net/problem/4963
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Pair
{
    private int first;
    private int second;
    
    Pair(int first, int second)
    {
        this.first = first;
        this.second = second;
    }
    
    public int getFirst()
    {
        return first;
    }
    
    public int getSecond()
    {
        return second;
    }
}

public class Main
{
    private static int[][] ocean;
    private static int w;
    private static int h;
    
    private static int[] yMove = {-1, -1, 0, 1, 1, 1, 0, -1};
    private static int[] xMove = {0, 1, 1, 1, 0, -1, -1, -1};
    
    public static void bfs(int y, int x, boolean[][] isVisited)
    {
        Queue<Pair> q = new LinkedList<Pair>();
        isVisited[y][x] = true;
        q.offer(new Pair(y, x));
        while (!q.isEmpty())
        {
            Pair temp = q.poll();
            y = temp.getFirst();
            x = temp.getSecond();
            for (int i = 0; i < 8; i++)
            {
                int n_y = y + yMove[i];
                int n_x = x + xMove[i];
                
                if (n_y < 0 || n_y >= h || n_x < 0 || n_x >= w) continue;
                if (isVisited[n_y][n_x] == false && ocean[n_y][n_x] == 1)
                {
                    isVisited[n_y][n_x] = true;
                    q.offer(new Pair(n_y, n_x));
                }
            }
        }
    }
    
    public static void main(String[] args) throws IOException
    {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var result = new StringBuilder();
        ocean = new int[50][50];
        
        while (true)
        {
            String[] input = br.readLine().split(" ");
            w = Integer.parseInt(input[0]);
            h = Integer.parseInt(input[1]);
            
            if (w == h && h == 0) break;
            
            for (int i = 0; i < h; i++)
            {
                input = br.readLine().split(" ");
                for (int j = 0; j < w; j++)
                    ocean[i][j] = Integer.parseInt(input[j]);
            }
            
            var isVisited = new boolean[h][w];
            int count = 0;
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (isVisited[i][j] == false && ocean[i][j] == 1)
                    {
                        bfs(i, j, isVisited);
                        count++;
                    }
                }
            }
            result.append(count);
            result.append('\n');
        }
        System.out.print(result.toString());
    }
}