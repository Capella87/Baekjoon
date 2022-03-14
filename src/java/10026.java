// 백준 10026번 문제 : 적록색약
// https://www.acmicpc.net/problem/10026
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Pair // Implement pair in C++
{
    private int y;
    private int x;
    
    public Pair(int init_y, int init_x)
    {
        y = init_y;
        x = init_x;
    }
    
    public int first()
    {
        return y;
    }
    
    public int second()
    {
        return x;
    }
}

public class Main
{
    private static char[][] colorMap;
    private static boolean[][][] isVisited;
    private static int n;
    private static int[] yMove = {-1, 0, 1, 0};
    private static int[] xMove = {0, 1, 0, -1};
    
    public static int getArea(int isColorBlind)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!isVisited[i][j][isColorBlind]) // BFS based task.
                {
                    char initColor = colorMap[i][j];
                    if (isColorBlind == 1 && colorMap[i][j] == 'R') initColor = 'G';
                    
                    Queue<Pair> q = new LinkedList<Pair>();
                    
                    isVisited[i][j][isColorBlind] = true;
                    q.offer(new Pair(i, j));
                    while (!q.isEmpty())
                    {
                        Pair p = q.poll();
                        int y = p.first();
                        int x = p.second();
                        
                        for (int k = 0; k < 4; k++)
                        {
                            int n_y = y + yMove[k];
                            int n_x = x + xMove[k];
                            if (n_y < 0 || n_y >= n || n_x >= n || n_x < 0 || isVisited[n_y][n_x][isColorBlind] == true)
                                continue;
                            
                            if (isColorBlind == 1 && (initColor == 'G' && colorMap[n_y][n_x] != 'B' || initColor == 'B' && colorMap[n_y][n_x] == initColor))
                            {
                                isVisited[n_y][n_x][isColorBlind] = true;
                                q.offer(new Pair(n_y, n_x));
                            }
                            if (isColorBlind == 0 && initColor == colorMap[n_y][n_x])
                            {
                                isVisited[n_y][n_x][isColorBlind] = true;
                                q.offer(new Pair(n_y, n_x));
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
    
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n = Integer.parseInt(br.readLine());
        colorMap = new char[n][];
        isVisited = new boolean[n][n][2];
        for (int i = 0; i < n; i++)
        {
            String input = br.readLine();
            colorMap[i] = input.toCharArray();
        }
        
        System.out.printf("%d %d\n", getArea(0), getArea(1));
    }
}