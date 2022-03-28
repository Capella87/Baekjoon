// 백준 7562번 문제 : 나이트의 이동
// https://www.acmicpc.net/problem/7562
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Tuple
{
    public int y;
    public int x;
    public int z;
    
    Tuple(int y, int x, int z)
    {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

public class Main
{
    public static int yMove[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    public static int xMove[] = {-1, 1, 2, 2, 1, -1, -2, -2};
    
    public static int bfs(int size, int y, int x, int dest_y, int dest_x)
    {
        Queue<Tuple> q = new LinkedList<Tuple>();
        var isVisited = new boolean[size][size];
        int move = 0;
        
        isVisited[y][x] = true;
        q.offer(new Tuple(y, x, move));
        while (!q.isEmpty())
        {
            y = q.peek().y;
            x = q.peek().x;
            move = q.peek().z;
            q.remove();
            
            if (y == dest_y && x == dest_x) break;
            
            for (int i = 0; i < 8; i++)
            {
                int n_y = y + yMove[i];
                int n_x = x + xMove[i];
                
                if (n_y < 0 || n_y >= size || n_x < 0 || n_x >= size)
                    continue;
                if (isVisited[n_y][n_x] == false)
                {
                    isVisited[n_y][n_x] = true;
                    q.offer(new Tuple(n_y, n_x, move + 1));
                }
            }
        }
        
        return move;
    }
    
    public static void main(String[] args) throws IOException
    {
        var br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        var result = new StringBuffer();
        
        while (t > 0)
        {
            int n = Integer.parseInt(br.readLine());
            
            var st = new StringTokenizer(br.readLine());
            int src_y = Integer.parseInt(st.nextToken());
            int src_x = Integer.parseInt(st.nextToken());
            
            st = new StringTokenizer(br.readLine()); // Use StringTokenizer() to get input as an array-like.
            int dest_y = Integer.parseInt(st.nextToken());
            int dest_x = Integer.parseInt(st.nextToken());
            
            result.append(bfs(n, src_y, src_x, dest_y, dest_x) + "\n");
            t--;
        }
        
        System.out.print(result);
    }
}